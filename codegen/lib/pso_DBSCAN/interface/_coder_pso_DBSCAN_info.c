/*
 * File: _coder_pso_DBSCAN_info.c
 *
 * MATLAB Coder version            : 5.6
 * C/C++ source code generated on  : 29-Nov-2023 20:18:11
 */

/* Include Files */
#include "_coder_pso_DBSCAN_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789c6360f4f465646060e0638000096e08cd0be50b4069260654802ecf88a68e11553903"
      "2b030b8a3e987c3f944ececf2b49ad288170f2127353e13a53f27333"
      "f312f34a422a0b52198a528bf373ca5253c032699939a92199b9a9c1c81c3f102fd70d49"
      "0ace014981d8ce19a9c9d9c1a5b90c4519c50817e62073e0e1d180c3",
      "bf2c448687248ef01040938f768d75b18a09c9482dce2c8e2928ce8f77710a7676f4d3cb"
      "45734f0185eee121e01e987c6a7c5e7e66716a7c71496209b2fd0964"
      "da8f0e70d90f03d40a7f6902f6c1e4a3fd90c21fd9f3d01820e47f7e22dd834e23d47380"
      "e9e302b718e969dfa20333b6d0d33e181828fb2a7098476c7a12c361",
      "9f009abcb98f7f55905152518697577a46b86ba1a357606a922bc21d0104ec21e40e061c"
      "7c7a99df8043ff40958b0914ba0757bd2500954949a2ae7d6c38ed83"
      "c8a4e49726e5a4522fdd0ae2b40f551e25bc5392880e676ae5576125fa967fe6f9faebe9"
      "691f0c0cf7f22fd430cf32cfb3243c39c92922cfc4252b27d22c22d1",
      "65e8977f00acdc76c6", ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 2864U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("pso_DBSCAN"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath",
                emlrtMxCreateString("D:\\Thesis\\pso_DBSCAN.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739219.835625));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("sgyMwRAvkQgoxLOM50BWaG"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_pso_DBSCAN_info.c
 *
 * [EOF]
 */
