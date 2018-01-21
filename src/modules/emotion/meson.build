emotion_loaders = [
'generic', 
'gstreamer', 
'gstreamer1', 
'libvlc', 
'xine'
]

foreach emotion_loader : emotion_loaders
  generic_src = []
  generic_deps = []
  mod_install_dir = join_paths(dir_lib, 'emotion', 'modules', emotion_loader, module_arch)

  if get_option('emotion-loaders-disabler').contains(emotion_loader) == false 
    subdir(emotion_loader)

    shared_module(emotion_loader,
        generic_src,
        include_directories : config_dir,
        dependencies: [eina, evas, emotion, generic_deps],
        install: true,
        install_dir : mod_install_dir,
        c_args : package_c_args,
    )
    module_files += join_paths(mod_install_dir, 'lib'+emotion_loader+'.so')
  endif
endforeach