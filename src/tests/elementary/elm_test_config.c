#ifdef HAVE_CONFIG_H
# include "elementary_config.h"
#endif

#define ELM_INTERFACE_ATSPI_ACCESSIBLE_PROTECTED
#include <Elementary.h>
#include "elm_suite.h"

#include <stdbool.h>
typedef unsigned int uint;

START_TEST (elm_config_eoapi)
{
   elm_init(1, NULL);

   Eo *cfg = eo_provider_find(ecore_main_loop_get(), EFL_CONFIG_INTERFACE);
   fail_if(!cfg);

#define CONFIG_CHK(opt, typ, val) do { \
   typ old = elm_config_ ## opt ## _get(); \
   fail_if(old != efl_config_ ## typ ## _get(cfg, #opt)); \
   fail_if(!efl_config_ ## typ ## _set(cfg, #opt, val)); \
   fail_if(elm_config_ ## opt ## _get() != val); \
   fail_if(efl_config_ ## typ ## _get(cfg, #opt) != val); \
   } while (0)

#define CONFIG_CHKB(opt, val) CONFIG_CHK(opt, bool, val)
#define CONFIG_CHKI(opt, val) CONFIG_CHK(opt, int, val)
#define CONFIG_CHKD(opt, val) CONFIG_CHK(opt, double, val)

   // note: leaks badly
#define CONFIG_CHKS(opt, val) do { \
   const char *old = elm_config_ ## opt ## _get(); \
   fail_if(!eina_streq(old, efl_config_string_get(cfg, #opt))); \
   fail_if(!efl_config_string_set(cfg, #opt, val)); \
   fail_if(!eina_streq(elm_config_ ## opt ## _get(), val)); \
   fail_if(!eina_streq(efl_config_string_get(cfg, #opt), val)); \
   } while (0)

#define CONFIG_CHKE(opt, ival, sval) do { \
   elm_config_ ## opt ## _set(ival); \
   fail_if(!eina_streq(efl_config_string_get(cfg, #opt), sval)); \
   fail_if(!efl_config_string_set(cfg, #opt, sval)); \
   fail_if(!eina_streq(efl_config_string_get(cfg, #opt), sval)); \
   } while (0)

   CONFIG_CHKB(scroll_bounce_enabled, !old);
   CONFIG_CHKD(scroll_bounce_friction, 0);
   CONFIG_CHKD(scroll_page_scroll_friction, 0);
   CONFIG_CHKB(context_menu_disabled, !old);
   CONFIG_CHKD(scroll_bring_in_scroll_friction, 0);
   CONFIG_CHKD(scroll_zoom_friction, 0);
   CONFIG_CHKB(scroll_thumbscroll_enabled, !old);
   CONFIG_CHKI(scroll_thumbscroll_threshold, 0);
   CONFIG_CHKI(scroll_thumbscroll_hold_threshold, 0);
   CONFIG_CHKD(scroll_thumbscroll_momentum_threshold, 0);
   CONFIG_CHKI(scroll_thumbscroll_flick_distance_tolerance, 0);
   CONFIG_CHKD(scroll_thumbscroll_friction, 0);
   CONFIG_CHKD(scroll_thumbscroll_min_friction, 0);
   CONFIG_CHKD(scroll_thumbscroll_friction_standard, 0);
   CONFIG_CHKD(scroll_thumbscroll_border_friction, 0);
   CONFIG_CHKD(scroll_thumbscroll_sensitivity_friction, 1.0);
   CONFIG_CHKB(scroll_thumbscroll_smooth_start, 0);
   CONFIG_CHKB(scroll_animation_disable, 0);
   CONFIG_CHKD(scroll_accel_factor, 0);
   CONFIG_CHKD(scroll_thumbscroll_smooth_amount, 0);
   CONFIG_CHKD(scroll_thumbscroll_smooth_time_window, 0);
   CONFIG_CHKD(scroll_thumbscroll_acceleration_threshold, 0);
   CONFIG_CHKD(scroll_thumbscroll_acceleration_time_limit, 0);
   CONFIG_CHKD(scroll_thumbscroll_acceleration_weight, 0);
   CONFIG_CHKE(focus_autoscroll_mode, EFL_UI_FOCUS_AUTOSCROLL_MODE_NONE, "none");
   CONFIG_CHKE(slider_indicator_visible_mode, EFL_UI_SLIDER_INDICATOR_VISIBLE_MODE_ALWAYS, "always");
   CONFIG_CHKD(longpress_timeout, 0);
   CONFIG_CHKE(softcursor_mode, EFL_UI_SOFTCURSOR_MODE_ON, "on");
   CONFIG_CHKD(tooltip_delay, 0);
   CONFIG_CHKB(cursor_engine_only, 0);
   CONFIG_CHKD(scale, 0);
   CONFIG_CHKS(icon_theme, ELM_CONFIG_ICON_THEME_ELEMENTARY);
   CONFIG_CHKB(password_show_last, 0);
   CONFIG_CHKD(password_show_last_timeout, 0);
   CONFIG_CHKS(preferred_engine, 0);
   CONFIG_CHKS(accel_preference, 0);
   //font_overlay
   CONFIG_CHKB(access, 0);
   CONFIG_CHKB(selection_unfocused_clear, 0);
   //elm_config_font_overlay_unset
   //CONFIG_CHKI(font_hint_type, 0); // this has no get!
   CONFIG_CHKI(finger_size, 0);
   CONFIG_CHKI(cache_flush_interval, 10);
   CONFIG_CHKB(cache_flush_enabled, !old);
   CONFIG_CHKI(cache_font_cache_size, 0);
   CONFIG_CHKI(cache_image_cache_size, 0);
   CONFIG_CHKI(cache_edje_file_cache_size, 0);
   CONFIG_CHKI(cache_edje_collection_cache_size, 0);
   CONFIG_CHKB(vsync, 0);
   CONFIG_CHKB(accel_preference_override, 0);
   CONFIG_CHKB(focus_highlight_enabled, !old);
   CONFIG_CHKB(focus_highlight_animate, 0);
   CONFIG_CHKB(focus_highlight_clip_disabled, !old);
   CONFIG_CHKE(focus_move_policy, EFL_UI_FOCUS_MOVE_POLICY_IN, "in");
   CONFIG_CHKB(item_select_on_focus_disabled, !old);
   CONFIG_CHKB(first_item_focus_on_first_focusin, 0);
   CONFIG_CHKB(mirrored, 0);
   CONFIG_CHKB(clouseau_enabled, !old);
   CONFIG_CHKD(glayer_long_tap_start_timeout, 0);
   CONFIG_CHKD(glayer_double_tap_timeout, 0);
   //color_overlay
   //color_overlay_unset
   CONFIG_CHKB(magnifier_enable, 0);
   CONFIG_CHKD(magnifier_scale, 0);
   CONFIG_CHKB(window_auto_focus_enable, 0);
   CONFIG_CHKB(window_auto_focus_animate, 0);
   CONFIG_CHKB(popup_scrollable, 0);
   CONFIG_CHKB(atspi_mode, 0);
   CONFIG_CHKD(transition_duration_factor, 0);
   CONFIG_CHKS(web_backend, old); // no value change (requires web support)

   static const struct {
      Edje_Channel chan;
      const char  *name;
   } channels[] = {
   { EDJE_CHANNEL_EFFECT, "audio_mute_effect" },
   { EDJE_CHANNEL_BACKGROUND, "audio_mute_background" },
   { EDJE_CHANNEL_MUSIC, "audio_mute_music" },
   { EDJE_CHANNEL_FOREGROUND, "audio_mute_foreground" },
   { EDJE_CHANNEL_INTERFACE, "audio_mute_interface" },
   { EDJE_CHANNEL_INPUT, "audio_mute_input" },
   { EDJE_CHANNEL_ALERT, "audio_mute_alert" },
   { EDJE_CHANNEL_ALL, "audio_mute_all" },
   { EDJE_CHANNEL_ALL, "audio_mute" },
   };

   for (unsigned i = 0; i < (sizeof(channels) / sizeof(channels[0])); i++)
     {
        Eina_Bool b = elm_config_audio_mute_get(channels[i].chan);
        if (b != efl_config_bool_get(cfg, channels[i].name))
          fail(channels[i].name);
        efl_config_bool_set(cfg, channels[i].name, !b);
        if(efl_config_bool_get(cfg, channels[i].name) != !b)
          fail(channels[i].name);
        if(elm_config_audio_mute_get(channels[i].chan) != !b)
          fail(channels[i].name);
     }

   elm_shutdown();
}
END_TEST

void elm_test_config(TCase *tc)
{
 tcase_add_test(tc, elm_config_eoapi);
}
