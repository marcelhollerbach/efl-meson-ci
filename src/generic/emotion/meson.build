if get_option('emotion-loaders-disabler').contains('libvlc') == false
  if libvlc.version() < '3.0'
    subdir('vlc')
  else
    message('module vlc will be used!')
  endif
endif
