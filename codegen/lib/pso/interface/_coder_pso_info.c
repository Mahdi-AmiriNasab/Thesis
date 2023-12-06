/*
 * File: _coder_pso_info.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 06-Dec-2023 18:10:23
 */

/* Include Files */
#include "_coder_pso_info.h"
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
  const char_T *data[8] = {
      "789ced59cb6ed3401475aaf2108f360809c44bed068955d4f4010d62d3bcda26699c26e9"
      "236a516a3b43626a8fd3d8096916287f808410125fc077b0630d3b16"
      "ac59f20348d47526f1184649eb74da587317995c1dcf9c3bd79ee3eb19ceb7bae6e3386e"
      "82b3ecd79cd5deecf8fe4e3bc6e1e6c47d9df69ac34776891bc7fa21",
      "fc5da795346880a66139505041b7674953652840237f58055c0de89ad200a563e495ac80"
      "bcac829cdd499b9e1ab7415dc784ccff910a90f6737595ab55f45e84"
      "8adde9e6a34d98eff880f99822e4c3efc077622f63cf77f315a0cbfa6e55d702aaefe8b7"
      "28400dc62518ecc65375198f33ffce78102e0a8a0025509434dd8873",
      "bd7cecb9e4bf4ce4b7909256171530bcfc3f24f2e138967f6cf201d5c4fbcd7f72c0789c"
      "6deffaabc76dfcc90f1f4dbe2b5fdf4fd1e443765e7c4dc278833e4f"
      "77087c7e079eaa655299b0dc50786921d20a25f9823e9b8bf4e2c8f4e1e9170747f0698d"
      "df26f43faf75e9561749ef2dbf033745391ace4596d2963faaba788f",
      "c887e3cef75267f256f2397aebf82e655d9cfbf091a7c987ccebbad810e19be66c39945c"
      "dc10c4cda4105ecb2da7a34c17cf6a5dbad5c51b7de2413828424dd6"
      "41513704c3cebf774a7ea791f8910d2bff0ffaf0217c276dcbbf7df29d3b406b1dbff5d3"
      "d5c5f1c2977d9a7cc8bcae8bcf527c2b3b2bd62a8944b9b2153b584a",
      "ac0331c6749176bd32683c630ebf178f8594c4e1f29db43e74fbdcde22f2e13896ef9248"
      "bd2efcfd98aefe4d06fe7ca6c987ccebfab7118421b86a6c4962781b"
      "ce475f2b85a7db02ab0b2fecf7f2f53ef1201c85a06b1267e7df73c9df4f0f75a356978c"
      "e1e5ff3e910fc7ff9bffa3c92361f4eaf7f28bdb9b224d3e645ed745",
      "be20b432f9b564b41a9c692c378c56221bd4c34c17cf4a1769d54d92a04875453040516b"
      "809a22203d1ed5fdc469221f8e63f7e19f240454afd68d9f920b0734"
      "f990795d1fe7b206cc2c8395f902bf1e5ad266f45634afc5993e5ed4ba71c2e13be341b8"
      "a2958b9252d70d509361797475f111910fc7b1fce3933fbe01b4d6f1",
      "34e5baf11bf7fd274d3e645ed7c5ca42893792a964622b7f185a4c659b2beb9516ab1bcf"
      "6c5dbad54576fe8c5fc7ce9fd9f9b369ecfcf964e3b709fd475517d9"
      "3e237e1ddb6764fb8ca6b17dc6938ddf26f43f2f5d64fb8ca7e39b26f2e138db67a4c387"
      "ccebfae8d57dc6bf0fa2f99e",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 13312U, &nameCaptureInfo);
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
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[6] = {"Version",      "ResolvedFunctions",
                                    "Checksum",     "EntryPoints",
                                    "CoverageInfo", "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 5);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"pso"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(5.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"FullPath",
                emlrtMxCreateString((const char_T *)"E:\\Thesis\\pso.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(739223.7274305555));
  xResult =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, (const char_T *)"Version",
                emlrtMxCreateString((const char_T *)"9.12.0.1884302 (R2022a)"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"Checksum",
                emlrtMxCreateString((const char_T *)"PvlPGterRwprrcHv76w8oE"));
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_pso_info.c
 *
 * [EOF]
 */
