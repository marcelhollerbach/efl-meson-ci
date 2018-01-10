mods = ['ibus', 'xim', 'scim']

if get_option('ecore_wl2')
  mods += ['wayland']
endif

loader_disabler = get_option('ecore-imf-loaders-disabler')

foreach mod_name : mods
  mod_src = []
  mod_deps = []

  if loader_disabler.contains(mod_name) == false
    subdir(mod_name)
    
    config_h.set('BUILD_ECORE_IMF_'+mod_name.to_upper(), '1')

    mod_install_dir =  join_paths(dir_package_modules, mod_name, module_arch)

    shared_module(mod_name,
        mod_src,
        dependencies: mod_deps,
        install: true,
        install_dir : mod_install_dir
    )
    module_files += join_paths(mod_install_dir, 'lib'+mod_name+'.so')
  endif
endforeach
