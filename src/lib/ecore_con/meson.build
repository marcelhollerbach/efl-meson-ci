ecore_con_deps = []

pub_legacy_eo_files = [
  'ecore_con_eet_base.eo',
  'ecore_con_eet_server_obj.eo',
  'ecore_con_eet_client_obj.eo'
]

pub_eo_file_target = []
foreach eo_file : pub_legacy_eo_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h', eo_file + '.legacy.h',],
    install : true,
    install_dir : dir_package_include,
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-o', 'c:' + join_paths(meson.current_build_dir(), eo_file + '.c'),
                           '-o', 'l:' + join_paths(meson.current_build_dir(), eo_file + '.legacy.h'),
                           '-gchl', '@INPUT@'])

endforeach

pub_eo_files = [
  'efl_net_socket.eo',
  'efl_net_socket_simple.eo',
  'efl_net_socket_fd.eo',
  'efl_net_socket_tcp.eo',
  'efl_net_socket_udp.eo',
  'efl_net_dialer.eo',
  'efl_net_dialer_simple.eo',
  'efl_net_dialer_tcp.eo',
  'efl_net_dialer_udp.eo',
  'efl_net_dialer_http.eo',
  'efl_net_dialer_websocket.eo',
  'efl_net_server.eo',
  'efl_net_server_simple.eo',
  'efl_net_server_fd.eo',
  'efl_net_server_ip.eo',
  'efl_net_server_tcp.eo',
  'efl_net_server_udp.eo',
  'efl_net_server_udp_client.eo',
  'efl_net_socket_ssl.eo',
  'efl_net_ssl_context.eo',
  'efl_net_dialer_ssl.eo',
  'efl_net_server_ssl.eo',
  'efl_net_control_access_point.eo',
  'efl_net_control_technology.eo',
  'efl_net_control.eo',
  'efl_net_session.eo',
  'efl_net_ip_address.eo',
]

if target_machine.system() == 'windows'
pub_eo_files += [
  'efl_net_socket_windows.eo',
  'efl_net_dialer_windows.eo',
  'efl_net_server_windows.eo'
]
else
pub_eo_files += [
  'efl_net_socket_unix.eo',
  'efl_net_dialer_unix.eo',
  'efl_net_server_unix.eo'
]
endif

foreach eo_file : pub_eo_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h'],
    install : true,
    install_dir : dir_package_include,
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-o', 'c:' + join_paths(meson.current_build_dir(), eo_file + '.c'),
                           '-gch', '@INPUT@'])
endforeach


pub_eo_types_files = [
  'efl_net_types.eot',
  'efl_net_http_types.eot',
  'efl_net_ssl_types.eot'
]

foreach eo_file : pub_eo_types_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h'],
    install : true,
    install_dir : dir_package_include,
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-gh', '@INPUT@'])
endforeach

eolian_include_directories += ['-I', meson.current_source_dir()]

ecore_con_header_src = [
  'Ecore_Con.h',
  'Efl_Net.h',
  'Ecore_Con_Eet.h',
  'Ecore_Con_Eet_Legacy.h',
  'Ecore_Con_Eet_Eo.h'
]

ecore_con_src = [
  'ecore_con_alloc.c',
  'ecore_con.c',
  'ecore_con_proxy_helper.c',
  'ecore_con_legacy.c',
  'ecore_con_eet.c',
  'ecore_con_socks.c',
  'ecore_con_url.c',
  'ecore_con_url_curl.c',
  'ecore_con_url_curl.h',
  'ecore_con_private.h',
  'efl_net_socket.c',
  'efl_net_socket_simple.c',
  'efl_net_socket_fd.c',
  'efl_net_socket_tcp.c',
  'efl_net_socket_udp.c',
  'efl_net_dialer.c',
  'efl_net_dialer_simple.c',
  'efl_net_dialer_tcp.c',
  'efl_net_dialer_udp.c',
  'efl_net_dialer_http.c',
  'efl_net_dialer_websocket.c',
  'efl_net_server.c',
  'efl_net_server_simple.c',
  'efl_net_server_fd.c',
  'efl_net_server_ip.c',
  'efl_net_server_tcp.c',
  'efl_net_server_udp.c',
  'efl_net_server_udp_client.c',
  'efl_net_socket_ssl.c',
  'efl_net_ssl_context.c',
  'efl_net_dialer_ssl.c',
  'efl_net_server_ssl.c',
  'ecore_con_local.c',
  'efl_net_ip_address.c'
]

if target_machine.system() == 'windows'
  ecore_con_src += [
    'efl_net_socket_windows.c',
    'efl_net_dialer_windows.c',
    'efl_net_server_windows.c'
  ]
else
  ecore_con_src += [
    'efl_net_socket_unix.c',
    'efl_net_dialer_unix.c',
    'efl_net_server_unix.c'
  ]
endif

if get_option('network-backend') == 'none'
  ecore_con_src += [
    'efl_net_control_access_point-none.c',
    'efl_net_control_technology-none.c',
    'efl_net_control-none.c',
    'efl_net_session-none.c'
  ]
else 
  ecore_con_src += [
    'efl_net-connman.h',
    'efl_net-connman.c',
    'efl_net_control_access_point-connman.c',
    'efl_net_control_technology-connman.c',
    'efl_net_control-connman.c',
    'efl_net_session-connman.c'
  ]
  ecore_con_deps += eldbus
endif


if (get_option('crypto') == 'gnutls')
  ecore_con_deps += gnutls
elif (get_option('crypto') == 'openssl')
  ecore_con_deps += openssl
endif

ecore_con_lib = library('ecore_con',
    ecore_con_src, pub_eo_file_target,
    dependencies: [ecore, ecore_con_deps, http_parser, eldbus, eet, systemd, dl],
    include_directories : config_dir,
    install: true,
    c_args : package_c_args,
)

ecore_con = declare_dependency(
  include_directories: [include_directories('.')],
  link_with: ecore_con_lib,
  sources : pub_eo_file_target,
  dependencies: [eina, eo, efl],
)

install_data(pub_eo_files,
  install_dir: join_paths(eolian_include_dir, package_version_name)
)

install_headers(ecore_con_header_src,
  install_dir : dir_package_include,
)