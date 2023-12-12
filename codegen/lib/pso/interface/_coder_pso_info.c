/*
 * File: _coder_pso_info.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 11-Dec-2023 16:05:35
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
      "789ced59dd6e1241145e9a6a8c3f2dc644e35fec8d89178694d26a31de40f969a1050af4"
      "87b486ce2e2360776728bb20e5c2f006de18139fc0c730be82de79e1"
      "b597be8089ddc2c0ceea045ae8b46ce65c309c7c3bfb9d39bbf3edd9b3926b65cd2549d2"
      "94d4b65fbef678a3e3bb3be384449b1d7775c6ab369fd82569929a47",
      "f0f79d51c1c8800da3ed20a0c1eecc02d6ca0820237b58815215ea58adc3c231f2baacc2"
      "6c598319ab93303d2d6281ba8e0999ff974a50d9cfd434a95ad27b11"
      "aa56a79b8f1663bd9303e6e311231f6e1bbe137e157eb19b2d41bdacef5674ecd15c47bf"
      "7980308a28c8db8da732643cf6fcdbe321b80c5480149857b06e44a4",
      "5e3ef686e4bfcce46f23055c935538bafc3f60f2d138957f6af11ecdc4fbad7f7ac078ec"
      "63eff82bc7a3e7e90f174fbe9d2f01cc938fd879f13518e71bf47eba"
      "cde073dbf0d46628e70b447d759c06be8d78a8e205aa3fd88b23d587a75f1c12c3e775fe"
      "1663fe79edcb617591f5dc72db70539443c1cc5220d1f6c75517ef32",
      "f968dcfe5cea2cbe9d7c89df3ebef384af2efa3e7c4cf2e423e6745daccbe86d63aee88f"
      "2f6e0079330e826b9968222474f1acf6e5b0ba78bd4f3c04877984cb"
      "3acceb0630acfc7ba7e4b71b8b9fd8a8f27fbf0f1fc1771296fc5b17dfb902bcf6f13b37"
      "5f5d9ccc7ddde7c947cce9baf87c35d94ccfc9d5522c562c6d850f02",
      "b1752887852ef2ae57068d67c2e6f7e269230579b47c27ad0f87bd6f6f32f9689cca7741"
      "e65e17fe7ecc57ffa63d7f3ef3e423e674fddbf0223f5a31b61439b8"
      "8de6436fd4dcb36d20eac20bfbbe7cad4f3c042721e85891acfc7b43f2f7d343dda8d614"
      "6374f9bfc7e4a3f1ffe6ff68f144189dfabefcf2d6a6cc938f98d375",
      "319903cd5476cd6c20ced6a375a3194b7b75d1473c335de455372940556a2a30601ed761"
      "5505448fc7b59f38c3e4a371ea3afc93048fe6d4baf1537ce180271f"
      "31a7eba32f6da054142ecfe792ebfe009ed59ba12c8e087dbca875e394cdb7c743701517"
      "f38a5ad30d582da3e2f8eae243261f8d53f9a7177f7c0178ede319ce",
      "75e337e9fb4f9e7cc49cae8ba58542d288afc6635bd943ffe26abab1bc5e6a8abaf1ccf6"
      "e5b0ba28be3fd3c789efcfe2fbb369e2fbf3c9cedf62cc1f575d147d"
      "46fa38d167147d46d3449ff164e76f31e69f972e8a3ee3e9f866987c342efa8c7cf88839"
      "5d1f9dda67fc0b1ab3f95b",
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
                emlrtMxCreateString((const char_T *)"iz9lo6OM2fDLNdFZnydNhC"));
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_pso_info.c
 *
 * [EOF]
 */
