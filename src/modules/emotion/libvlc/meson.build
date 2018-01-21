libvlc = dependency('libvlc')

if libvlc.version() >= '3.0'
  generic_src = files([
    'emotion_libvlc.c',
  ])
  generic_deps = [dependency('libvlc', version: '>= 3.0')]
else
  message('Generic vlc will be used!')
endif
