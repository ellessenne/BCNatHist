// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// EvalCaseIntegral
double EvalCaseIntegral(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_EvalCaseIntegral(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP tSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t(tSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(EvalCaseIntegral(age, v, scr, par, t, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// EvalCensIntegral
double EvalCensIntegral(double age, arma::rowvec scr, arma::vec par, arma::colvec t, arma::colvec t_wts, arma::rowvec r, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_EvalCensIntegral(SEXP ageSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP tSEXP, SEXP t_wtsSEXP, SEXP rSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t(tSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(EvalCensIntegral(age, scr, par, t, t_wts, r, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// CalcScreenCase
double CalcScreenCase(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_CalcScreenCase(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(CalcScreenCase(age, v, scr, par, t_pts, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// CalcSymptCase
double CalcSymptCase(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_CalcSymptCase(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(CalcSymptCase(age, v, scr, par, t_pts, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// CalcCensCase
double CalcCensCase(double age, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, arma::rowvec r_pts, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_CalcCensCase(SEXP ageSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP r_ptsSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_pts(r_ptsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(CalcCensCase(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// IndL
double IndL(int is_case, int is_scr, double age, double v, arma::rowvec scr, double entry, arma::rowvec e_scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, arma::rowvec r_pts, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_IndL(SEXP is_caseSEXP, SEXP is_scrSEXP, SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP entrySEXP, SEXP e_scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP r_ptsSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type is_case(is_caseSEXP);
    Rcpp::traits::input_parameter< int >::type is_scr(is_scrSEXP);
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< double >::type entry(entrySEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type e_scr(e_scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_pts(r_ptsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(IndL(is_case, is_scr, age, v, scr, entry, e_scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// f_CaseIntegral_odg
double f_CaseIntegral_odg(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_f_CaseIntegral_odg(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP tSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t(tSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(f_CaseIntegral_odg(age, v, scr, par, t, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// f_CensIntegral_odg
double f_CensIntegral_odg(double age, arma::rowvec scr, arma::vec par, arma::colvec t, arma::colvec t_wts, arma::rowvec r, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_f_CensIntegral_odg(SEXP ageSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP tSEXP, SEXP t_wtsSEXP, SEXP rSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t(tSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r(rSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(f_CensIntegral_odg(age, scr, par, t, t_wts, r, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// f_ScreenCase_odg
double f_ScreenCase_odg(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_f_ScreenCase_odg(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(f_ScreenCase_odg(age, v, scr, par, t_pts, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// f_SymptCase_odg
double f_SymptCase_odg(double age, double v, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_f_SymptCase_odg(SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(f_SymptCase_odg(age, v, scr, par, t_pts, t_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// f_CensCase_odg
double f_CensCase_odg(double age, arma::rowvec scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, arma::rowvec r_pts, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_f_CensCase_odg(SEXP ageSEXP, SEXP scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP r_ptsSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_pts(r_ptsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(f_CensCase_odg(age, scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}
// IndL_odg
double IndL_odg(int is_case, int is_scr, double age, double v, arma::rowvec scr, double entry, arma::rowvec e_scr, arma::vec par, arma::colvec t_pts, arma::colvec t_wts, arma::rowvec r_pts, arma::rowvec r_wts, double d0, double v0);
RcppExport SEXP _BCNatHist_IndL_odg(SEXP is_caseSEXP, SEXP is_scrSEXP, SEXP ageSEXP, SEXP vSEXP, SEXP scrSEXP, SEXP entrySEXP, SEXP e_scrSEXP, SEXP parSEXP, SEXP t_ptsSEXP, SEXP t_wtsSEXP, SEXP r_ptsSEXP, SEXP r_wtsSEXP, SEXP d0SEXP, SEXP v0SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type is_case(is_caseSEXP);
    Rcpp::traits::input_parameter< int >::type is_scr(is_scrSEXP);
    Rcpp::traits::input_parameter< double >::type age(ageSEXP);
    Rcpp::traits::input_parameter< double >::type v(vSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type scr(scrSEXP);
    Rcpp::traits::input_parameter< double >::type entry(entrySEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type e_scr(e_scrSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type par(parSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_pts(t_ptsSEXP);
    Rcpp::traits::input_parameter< arma::colvec >::type t_wts(t_wtsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_pts(r_ptsSEXP);
    Rcpp::traits::input_parameter< arma::rowvec >::type r_wts(r_wtsSEXP);
    Rcpp::traits::input_parameter< double >::type d0(d0SEXP);
    Rcpp::traits::input_parameter< double >::type v0(v0SEXP);
    rcpp_result_gen = Rcpp::wrap(IndL_odg(is_case, is_scr, age, v, scr, entry, e_scr, par, t_pts, t_wts, r_pts, r_wts, d0, v0));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_BCNatHist_EvalCaseIntegral", (DL_FUNC) &_BCNatHist_EvalCaseIntegral, 8},
    {"_BCNatHist_EvalCensIntegral", (DL_FUNC) &_BCNatHist_EvalCensIntegral, 9},
    {"_BCNatHist_CalcScreenCase", (DL_FUNC) &_BCNatHist_CalcScreenCase, 8},
    {"_BCNatHist_CalcSymptCase", (DL_FUNC) &_BCNatHist_CalcSymptCase, 8},
    {"_BCNatHist_CalcCensCase", (DL_FUNC) &_BCNatHist_CalcCensCase, 9},
    {"_BCNatHist_IndL", (DL_FUNC) &_BCNatHist_IndL, 14},
    {"_BCNatHist_f_CaseIntegral_odg", (DL_FUNC) &_BCNatHist_f_CaseIntegral_odg, 8},
    {"_BCNatHist_f_CensIntegral_odg", (DL_FUNC) &_BCNatHist_f_CensIntegral_odg, 9},
    {"_BCNatHist_f_ScreenCase_odg", (DL_FUNC) &_BCNatHist_f_ScreenCase_odg, 8},
    {"_BCNatHist_f_SymptCase_odg", (DL_FUNC) &_BCNatHist_f_SymptCase_odg, 8},
    {"_BCNatHist_f_CensCase_odg", (DL_FUNC) &_BCNatHist_f_CensCase_odg, 9},
    {"_BCNatHist_IndL_odg", (DL_FUNC) &_BCNatHist_IndL_odg, 14},
    {NULL, NULL, 0}
};

RcppExport void R_init_BCNatHist(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
