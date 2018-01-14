evas_lib = library('evas', 
    'empty.c',
    #all the source code is coming from evas_pre_lib_dep
    dependencies: [evas_pre_lib_dep, evas_static_list],
    install: true,
    c_args : '-DPACKAGE_DATA_DIR="'+join_paths(dir_data, 'evas')+'"',
)

evas = declare_dependency(
   link_with : [evas_lib],
   include_directories: evas_include_directories + [vg_common_inc_dir],
   dependencies : [eina, ecore, ector, emile, eo, evas_deps],
   sources : evas_pub_eo_file_target,
)

evas_bin = declare_dependency(
   link_with : [evas_lib],
   dependencies : [eina, ecore, ector, emile, dependency('luajit')],
   include_directories : evas_include_directories
)