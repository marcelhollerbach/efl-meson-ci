pub_legacy_eo_files = [
  'efl_gfx_fill.eo',
  'efl_gfx.eo',
  'efl_gfx_color.eo',
  'efl_image.eo',
  'efl_image_animated.eo',
  'efl_input_device.eo',
  'efl_ui_draggable.eo',
  'efl_ui_clickable.eo',
  'efl_ui_scrollable.eo',
  'efl_ui_scrollable_interactive.eo',
  'efl_ui_scrollbar.eo',
  'efl_ui_selectable.eo',
  'efl_ui_zoom.eo',
]

pub_eo_file_target = []
foreach eo_file : pub_legacy_eo_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h', eo_file + '.legacy.h',],
    install : true,
    install_dir : join_paths(dir_package_include, 'interfaces'),
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-o', 'c:' + join_paths(meson.current_build_dir(), eo_file + '.c'),
                           '-o', 'l:' + join_paths(meson.current_build_dir(), eo_file + '.legacy.h'),
                           '-gchl', '@INPUT@'])

endforeach

pub_eo_files = [
  'efl_canvas.eo',
  'efl_canvas_pointer.eo',
  'efl_config.eo',
  'efl_control.eo',
  'efl_duplicate.eo',
  'efl_file.eo',
  'efl_image_load.eo',
  'efl_part.eo',
  'efl_player.eo',
  'efl_text.eo',
  'efl_text_font.eo',
  'efl_text_style.eo',
  'efl_text_format.eo',
  'efl_text_cursor.eo',
  'efl_text_annotate.eo',
  'efl_text_markup.eo',
  'efl_text_markup_util.eo',
  'efl_text_properties.eo',
  'efl_gfx_stack.eo',
  'efl_gfx_view.eo',
  'efl_gfx_buffer.eo',
  'efl_gfx_path.eo',
  'efl_gfx_shape.eo',
  'efl_gfx_gradient.eo',
  'efl_gfx_gradient_linear.eo',
  'efl_gfx_gradient_radial.eo',
  'efl_gfx_filter.eo',
  'efl_gfx_blur.eo',
  'efl_gfx_size_hint.eo',
  'efl_model.eo',
  'efl_animator.eo',
  'efl_orientation.eo',
  'efl_flipable.eo',
  'efl_container.eo',
  'efl_content.eo',
  'efl_pack.eo',
  'efl_pack_layout.eo',
  'efl_pack_linear.eo',
  'efl_pack_table.eo',
  'efl_vpath.eo',
  'efl_vpath_manager.eo',
  'efl_vpath_file.eo',
  'efl_vpath_core.eo',
  'efl_vpath_file_core.eo',
  'efl_ui_base.eo',
  'efl_ui_direction.eo',
  'efl_ui_drag.eo',
  'efl_ui_range.eo',
  'efl_ui_view.eo',
  'efl_ui_model_connect.eo',
  'efl_ui_factory.eo',
  'efl_ui_model_factory_connect.eo',
  'efl_screen.eo',
  'efl_io_closer.eo',
  'efl_io_positioner.eo',
  'efl_io_reader.eo',
  'efl_io_sizer.eo',
  'efl_io_writer.eo',
  'efl_io_buffer.eo',
  'efl_io_queue.eo',
  'efl_observer.eo',
  'efl_observable.eo',
  'efl_ui_item.eo',
  'efl_ui_menu.eo',
  'efl_ui_autorepeat.eo',
  'efl_ui_format.eo',
  'efl_gfx_color_class.eo',
  'efl_gfx_text_class.eo',
  'efl_gfx_size_class.eo',
]

#FIXME efl depends on evas ... YEAH
eolian_include_directories += ['-I', join_paths(meson.source_root(), 'src', 'lib', 'evas', 'canvas')]

foreach eo_file : pub_eo_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h'],
    install : true,
    install_dir : join_paths(dir_package_include, 'interfaces'),
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-o', 'c:' + join_paths(meson.current_build_dir(), eo_file + '.c'),
                           '-gch', '@INPUT@'])
endforeach

pub_eo_types_files = [
  'efl_gfx_types.eot',
  'efl_ui_types.eot',
  'efl_input_types.eot',
  'efl_types.eot',
  'efl_text_types.eot',
]

foreach eo_file : pub_eo_types_files
  pub_eo_file_target += custom_target('eolian_gen_' + eo_file,
    input : eo_file,
    output : [eo_file + '.h'],
    install : true,
    install_dir : join_paths(dir_package_include, 'interfaces'),
    command : [eolian_gen, '-I', meson.current_source_dir(), eolian_include_directories,
                           '-o', 'h:' + join_paths(meson.current_build_dir(), eo_file + '.h'),
                           '-gh', '@INPUT@'])
endforeach

pub_eo_files = files(pub_eo_files + pub_legacy_eo_files)

efl_src += files([
  'efl_interfaces_main.c',
  'efl_model_common.c',
  'efl_gfx_path.c',
  'efl_gfx_shape.c',
  'efl_gfx_color.c',
  'efl_vpath_file.c',
  'efl_vpath_manager.c',
  'efl_vpath_core.c',
  'efl_vpath_file_core.c',
  'efl_input_device.c',
  'efl_io_closer.c',
  'efl_io_positioner.c',
  'efl_io_reader.c',
  'efl_io_sizer.c',
  'efl_io_writer.c',
  'efl_io_buffer.c',
  'efl_io_queue.c',
  'efl_observer.c',
  'efl_file.c',
  'efl_ui_format.c',
  'efl_text_markup_util.c',
])

efl_header_src += files([
  'efl_common_internal.h'
])

eolian_include_directories += ['-I', meson.current_source_dir()]
