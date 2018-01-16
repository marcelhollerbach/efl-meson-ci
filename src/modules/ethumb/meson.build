emotion_loaders = [
'emotion'
]

foreach emotion_loader : emotion_loaders
  generic_src = []
  generic_deps = []
  mod_install_dir = join_paths(dir_lib, 'ethumb', 'modules', emotion_loader, module_arch)

  subdir(emotion_loader)

  shared_module(emotion_loader+'_loader',
      generic_src,
      include_directories : config_dir,
      dependencies: [eina, evas, emotion, generic_deps, evas, ecore, eo],
      install: true,
      install_dir : mod_install_dir,
      c_args : package_c_args,
  )

  module_files += join_paths(mod_install_dir, 'lib'+emotion_loader+'_loader.so')
endforeach