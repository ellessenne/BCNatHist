#include <RcppArmadillo.h>
#include "Likelihood.h"

// par[0] = A
// par[1] = B
// par[2] = delta
// par[3] = phi
// par[4] = mu
// par[5] = eta
// par[6] = beta_0
// par[7] = beta_s

//' @title EvalCaseIntegral
//' @description Evaluate the integral for BC cases
//' @export
// [[Rcpp::export]]
double EvalCaseIntegral(double age, double v, arma::rowvec scr, 
                    arma::vec par, arma::colvec t, arma::colvec t_wts, 
                    double d0 = 0.5, double v0 = 0.06544985){
  double out, L, C, a, b;
  arma::colvec e, x_t;
  arma::mat d, ix;
        
  t_wts *= 0.5 * age;
  t += 1;
  t *= 0.5 * age;

  L = std::log(v / v0);
  a = 1 / par[3];
  b = a / par[4];
  
  C = par[0] * par[1] * par[2] * std::pow(par[1] - par[0], par[2]) / 
      tgamma(a) * std::pow(b / L, a) / L;
  x_t = arma::exp((par[1] - par[0]) * t);
  d = d0 * arma::exp((((1 / (age - t)) * (scr - age)) + 1) * (L / 3));
  ix = arma::conv_to<arma::mat>::from(d > d0);

  e  = arma::log(age - t) * a; 
  e += par[1] * par[2] * t; 
  e -= (age - t) * ((b + par[5] * (v - v0)) / L);
  e -= arma::sum(arma::log(1 + arma::exp(par[7] + par[6] * d)) % ix , 1); 

  out = C * arma::sum(t_wts % arma::exp(e) % (1 - x_t) %
        pow(par[1] * x_t - par[0], -par[2] - 1));

  return out;
}

//' @title EvalCensIntegral
//' @description Evaluate the double integral for censored
//' @export
// [[Rcpp::export]]
double EvalCensIntegral(double age, arma::rowvec scr, arma::vec par,
                    arma::colvec t, arma::colvec t_wts,
                    arma::rowvec r, arma::rowvec r_wts,
                    double d0 = 0.5, double v0 = 0.06544985){
  double out, C, a, b;
  arma::colvec e_t, x_t;
  arma::rowvec e_r, r_inv;
  arma::mat e_tr, d, ix;

  arma::colvec ones(t.n_elem, arma::fill::ones);
  int n_scr = scr.n_elem; 

  t_wts *= 0.5 * age;
  t += 1;
  t *= 0.5 * age; 

  r_inv = 1 / r;
  x_t = arma::exp((par[1] - par[0]) * t);
  a = 1 / par[3];
  b = a / par[4];
  
  C = -par[0] * par[1] * par[2] * std::pow(par[1] - par[0], par[2]) * 
      std::pow(b, a) / tgamma(a); 

  e_t  = (par[1] * par[2]) * t; 
  e_t += arma::log(x_t - 1); 
  e_t -= (par[2] + 1) * arma::log(par[1] * x_t - par[0]);
  
  e_r  = (par[5] * v0 + 1) * r; // +1r for gauss-laguerre
  e_r += (a - 1) * arma::log(r); 
  e_r -= (r * b); 
  
  e_tr = (ones * ((-par[5] * v0) * r)) % arma::exp((age - t) * r_inv);
  if (n_scr > 0) {
    for (int i=0; i<n_scr; ++i) {
      d = d0 * arma::exp((scr[i] - t) * (r_inv / 3));
      ix = arma::conv_to<arma::mat>::from(d > d0);
      e_tr -= arma::log(1 + arma::exp(par[7] + par[6] * d)) % ix;
    }
  }

  out = C * arma::sum(arma::sum((t_wts * r_wts) %
        (arma::exp(e_t) * arma::exp(e_r)) % arma::exp(e_tr), 0)); 

  return out; 
}

//' @title CalcScreenCase
//' @description Calculate the joint likelihood of a single screen-detected case
//' @export
// [[Rcpp::export]]
double CalcScreenCase(double age, double v, arma::rowvec scr, arma::vec par, 
                  arma::colvec t_pts, arma::colvec t_wts, 
                  double d0 = 0.5, double v0 = 0.06544985) {
  double out;
  out = par[7] + par[6] * d0 * std::exp(std::log(v / v0) / 3) - std::log(v);
  out += std::log(EvalCaseIntegral(age, v, scr, par, t_pts, t_wts, d0, v0));
  out = std::exp(out);
  return out;
}

//' @title CalcSymptCase
//' @description Calculate the joint likelihood of a single symptomatic case
//' @export
// [[Rcpp::export]]
double CalcSymptCase(double age, double v, arma::rowvec scr, arma::vec par, 
                 arma::colvec t_pts, arma::colvec t_wts, 
                  double d0 = 0.5, double v0 = 0.06544985) {
  double out;
  out = par[5];
  out *= EvalCaseIntegral(age, v, scr, par, t_pts, t_wts, d0, v0);
  return out;
}

//' @title CalcCensCase
//' @description Calculate the joint likelihood of a single censored
//' @export
// [[Rcpp::export]]
double CalcCensCase(double age, arma::rowvec scr, arma::vec par, 
                arma::colvec t_pts, arma::colvec t_wts, 
                arma::rowvec r_pts, arma::rowvec r_wts,
                double d0 = 0.5, double v0 = 0.06544985) {
  double out;
  out = std::pow((par[1] - par[0]) * std::exp(par[1] * age) /
        (par[1] * std::exp((par[1] - par[0]) * age) - par[0]), par[2]);
  out += EvalCensIntegral(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  return out;
}

//' @title IndL
//' @description Determine case and mode status, and calculate the corresponding joint likelihood
//' @export
// [[Rcpp::export]]
double IndL(int is_case, int is_scr, double age, double v, arma::rowvec scr,
            double entry, arma::rowvec e_scr, arma::vec par,
            arma::colvec t_pts, arma::colvec t_wts,
            arma::rowvec r_pts, arma::rowvec r_wts,
            double d0 = 0.5, double v0 = 0.06544985) {
  double out;
  if(is_case == 0) {
    out = CalcCensCase(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  } else if (is_scr == 1) {
    out = CalcScreenCase(age, v, scr, par, t_pts, t_wts, d0, v0);
  } else {
    out = CalcSymptCase(age, v, scr, par, t_pts, t_wts, d0, v0);
  }

  out /= CalcCensCase(entry, e_scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  return out; 
}

////////////////////////////////////////////////////////////////////////////////
// Onset-Dependent Growth functions
////////////////////////////////////////////////////////////////////////////////

// [[Rcpp::export]]
double f_CaseIntegral_odg(double age, double v, arma::rowvec scr, 
                          arma::vec par, arma::colvec t, arma::colvec t_wts, 
                          double d0 = 0.5, double v0 = 0.06544985)
{
  double out, L, C, a;
  arma::colvec e, x_t, b;
  arma::mat d, ix;
  
  t_wts *= 0.5 * age;
  t += 1;
  t *= 0.5 * age;
  
  L = std::log(v / v0);
  a = 1 / par[3];
  b = arma::exp(-par[8] * t) / (par[3] * par[4]);
  x_t = arma::exp((par[1] - par[0]) * t);
  
  C = par[0] * par[1] * par[2] * std::pow(par[1] - par[0], par[2]) / 
    tgamma(a) / std::pow(L, a + 1);
  
  d = d0 * arma::exp((((1 / (age - t)) * (scr - age)) + 1) * (L / 3));
  ix = arma::conv_to<arma::mat>::from(d > d0);
  
  e  = arma::log(age - t) * a; 
  e += par[1] * par[2] * t; 
  e -= ((age - t) / L) % (b + par[5] * (v - v0));
  e += arma::log(b) * a;
  e -= arma::sum(arma::log(1 + arma::exp(par[7] + par[6] * d)) % ix , 1);
  
  out = C * arma::sum(t_wts % arma::exp(e) % (1 - x_t) %
    pow(par[1] * x_t - par[0], -par[2] - 1));
  
  return out;
}

// [[Rcpp::export]]
double f_CensIntegral_odg(double age, arma::rowvec scr, arma::vec par,
                          arma::colvec t, arma::colvec t_wts,
                          arma::rowvec r, arma::rowvec r_wts,
                          double d0 = 0.5, double v0 = 0.06544985)
{
  double out, C, a;
  arma::colvec e_t, x_t, b;
  arma::rowvec e_r, r_inv;
  arma::mat e_tr, d, ix;
  
  arma::colvec ones(t.n_elem, arma::fill::ones);
  int n_scr = scr.n_elem; 
  
  t_wts *= 0.5 * age;
  t += 1;
  t *= 0.5 * age; 
  
  r_inv = 1 / r;
  x_t = arma::exp((par[1] - par[0]) * t);
  a = 1 / par[3];
  b = arma::exp(-par[8] * t) / (par[3] * par[4]);
  
  C = -par[0] * par[1] * par[2] * std::pow(par[1] - par[0], par[2]) / 
    tgamma(a);
  
  e_t  = (par[1] * par[2]) * t + arma::log(b) * a ;
  e_t += arma::log(x_t - 1); 
  e_t -= (par[2] + 1) * arma::log(par[1] * x_t - par[0]);
  e_r  = (par[5] * v0 + 1) * r; // +1r for gauss-laguerre
  e_r += (a - 1) * arma::log(r); 
  // 
  e_tr = -b * r; 
  e_tr+= (ones * ((-par[5] * v0) * r)) % arma::exp((age - t) * r_inv);
  
  if (n_scr > 0) {
    for (int i=0; i<n_scr; ++i) {
      d = d0 * arma::exp((scr[i] - t) * (r_inv / 3));
      ix = arma::conv_to<arma::mat>::from(d > d0);
      e_tr -= arma::log(1 + arma::exp(par[7] + par[6] * d)) % ix;
    }
  }
  
  out = C * arma::sum(arma::sum((t_wts * r_wts) %
    (arma::exp(e_t) * arma::exp(e_r)) % arma::exp(e_tr), 0));

  return out;
  
}

// [[Rcpp::export]]
double f_ScreenCase_odg(double age, double v, arma::rowvec scr, arma::vec par, 
                        arma::colvec t_pts, arma::colvec t_wts, 
                        double d0 = 0.5, double v0 = 0.06544985) 
{
  double out = std::exp(par[7] + par[6] * d0 * std::exp(std::log(v / v0) / 3)) / v;
  out *= f_CaseIntegral_odg(age, v, scr, par, t_pts, t_wts, d0, v0);
  return out;
}
// [[Rcpp::export]]
double f_SymptCase_odg(double age, double v, arma::rowvec scr, arma::vec par, 
                       arma::colvec t_pts, arma::colvec t_wts, 
                       double d0 = 0.5, double v0 = 0.06544985) 
{
  double out = par[5];
  out *= f_CaseIntegral_odg(age, v, scr, par, t_pts, t_wts, d0, v0);
  return out;
}
// [[Rcpp::export]]
double f_CensCase_odg(double age, arma::rowvec scr, arma::vec par, 
                  arma::colvec t_pts, arma::colvec t_wts, 
                  arma::rowvec r_pts, arma::rowvec r_wts,
                  double d0 = 0.5, double v0 = 0.06544985) 
{
  double out = std::pow((par[1] - par[0]), par[2]) * 
    std::exp(par[1] * par[2] * age) /
      pow(par[1] * std::exp((par[1] - par[0]) * age) - par[0], par[2]);
  out += f_CensIntegral_odg(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  return out;
}
// [[Rcpp::export]]
double IndL_odg(int is_case, int is_scr, double age, double v, arma::rowvec scr,
            double entry, arma::rowvec e_scr, arma::vec par,
            arma::colvec t_pts, arma::colvec t_wts,
            arma::rowvec r_pts, arma::rowvec r_wts,
            double d0 = 0.5, double v0 = 0.06544985) {
  double out;
  if(is_case == 0) {
    out = f_CensCase_odg(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  } else if (is_scr == 1) {
    out = f_ScreenCase_odg(age, v, scr, par, t_pts, t_wts, d0, v0);
  } else {
    out = f_SymptCase_odg(age, v, scr, par, t_pts, t_wts, d0, v0);
  }
  
  out /= f_CensCase_odg(entry, e_scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0);
  return out;
}

