#include "src/traitsd.h"
#include "src/block3.h"

#include "constants/3dDouble.h"

#define CFP_ARRAY_TYPE cfp_array3d
#define CFP_REF_TYPE cfp_ref_array3d
#define CFP_PTR_TYPE cfp_ptr_array3d
#define CFP_ITER_TYPE cfp_iter_array3d

#define CFP_VIEW_TYPE cfp_flat_view3d
#define CFP_VIEW_REF_TYPE cfp_ref_flat_view3d
#define CFP_VIEW_PTR_TYPE cfp_ptr_flat_view3d
#define CFP_VIEW_ITER_TYPE cfp_iter_flat_view3d

#define SUB_NAMESPACE array3d
#define VIEW_NAMESPACE array3d.flat_view
#define SCALAR double
#define SCALAR_TYPE zfp_type_double
#define DIMENSIONALITY 3

#include "testCfpView_source.c"
#include "testCfpView3_source.c"
#include "testCfpFlatView_source.c"
#include "testCfpFlatView3_source.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(given_cfp_flat_view3d_when_ctor_expect_returnsNonNullPtr),

    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_ctor_subset_expect_returnsNonNullPtr, setupCfpArrSmall, teardownCfpArr),
    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_ijk_then_returnsUnflatIndices, setupCfpArrSmall, teardownCfpArr),

    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_setFlat_expect_getFlatEntryMatches, setupCfpViewSmall, teardownCfpView),
    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_size_expect_sizeMatches, setupCfpViewSmall, teardownCfpView),
    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_sizex_expect_sizeMatches, setupCfpViewSmall, teardownCfpView),
    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_getRate_expect_rateMatches, setupCfpViewSmall, teardownCfpView),
    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_set_expect_getValueMatches, setupCfpViewSmall, teardownCfpView),

    cmocka_unit_test_setup_teardown(given_cfp_flat_view3d_when_globalx_expect_offsetMatches, setupCfpSubsetViewSmall, teardownCfpView),
  };

  return cmocka_run_group_tests(tests, prepCommonSetupVars, teardownCommonSetupVars);
}
