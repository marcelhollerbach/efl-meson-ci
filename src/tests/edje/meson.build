subdir('data')
subdir('tests')

edje_suite_src = [
  'edje_suite.c',
  'edje_suite.h',
  'edje_test_edje.c',
  'edje_tests_helpers.h',
]

edje_suite = executable('edje_suite',
  edje_suite_src, themes,
  dependencies: [check, eina, edje],
  include_directories : config_dir,
  c_args : [
  '-DTESTS_BUILD_DIR="'+meson.current_build_dir()+'"',
  '-DTESTS_SRC_DIR="'+meson.current_source_dir()+'"']
)

test('edje-suite', edje_suite,
  is_parallel: true,
)