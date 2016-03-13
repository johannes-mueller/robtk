/*
  Copyright 2016 Robin Gareus <robin@gareus.org>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THIS SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef LV2_RG_EXT_H // -> needs to eventually go upstream to lv2plug.in
#define LV2_RG_EXT_H

/**
   @defgroup inlinedisplay Inline-Display

   Support for displaying a miniaturized generic view
	 directly in the host's Mixer Window.

   @{
*/

#define LV2_INLINEDISPLAY_URI "http://harrisonconsoles.com/lv2/inlinedisplay"
#define LV2_INLINEDISPLAY_PREFIX LV2_INLINEDISPLAY_URI "#"
#define LV2_INLINEDISPLAY__interface LV2_INLINEDISPLAY_PREFIX "interface"
#define LV2_INLINEDISPLAY__queue_draw LV2_INLINEDISPLAY_PREFIX "queue_draw"

/** Opaque handle for LV2_Inline_Display::queue_draw() */
typedef void* LV2_Inline_Display_Handle;

/** Alias for cairo_image_surface_t */
typedef void* LV2_Inline_Display_Image_Surface;

typedef struct {
	/** Opaque host data */
	LV2_Inline_Display_Handle handle;
	/** Request from run() that the host should call render() */
	void (*queue_draw)(LV2_Inline_Display_Handle handle);
} LV2_Inline_Display;

/**
 * Plugin Inline-Display Interface.
 */
typedef struct {
	/**
	 * The render method. This is called by the host in a non-realtime context,
	 * usually the main GUI thread.
	 *
	 * @param instance The LV2 instance
	 * @param w the max available width
	 * @return pointer to a cairo image surface or NULL
	 */
	LV2_Inline_Display_Image_Surface (*render)(LV2_Handle instance, uint32_t w, uint32_t h);
} LV2_Inline_Display_Interface;

/**
   @}
*/

/**
   @defgroup automate Self-Automation

   Support for plugins to write automation data via Atom Events

   @{
*/

#define LV2_AUTOMATE_URI "http://ardour.org/lv2/automate"
#define LV2_AUTOMATE_URI_PREFIX LV2_AUTOMATE_URI "#"
/** an lv2:optionalFeature */
#define LV2_AUTOMATE_URI__can_write LV2_AUTOMATE_URI_PREFIX "canWriteAutomatation"
/** atom:supports */
#define LV2_AUTOMATE_URI__control LV2_AUTOMATE_URI_PREFIX "automationControl"
/** lv2:portProperty */
#define LV2_AUTOMATE_URI__controlled LV2_AUTOMATE_URI_PREFIX "automationControlled"

/** atom messages */
#define LV2_AUTOMATE_URI__event LV2_AUTOMATE_URI_PREFIX "event"
#define LV2_AUTOMATE_URI__setup LV2_AUTOMATE_URI_PREFIX "setup"
#define LV2_AUTOMATE_URI__finalize LV2_AUTOMATE_URI_PREFIX "finalize"
#define LV2_AUTOMATE_URI__start LV2_AUTOMATE_URI_PREFIX "start"
#define LV2_AUTOMATE_URI__end LV2_AUTOMATE_URI_PREFIX "end"
#define LV2_AUTOMATE_URI__parameter LV2_AUTOMATE_URI_PREFIX "parameter"
#define LV2_AUTOMATE_URI__value LV2_AUTOMATE_URI_PREFIX "value"

/**
   @}
*/

#endif
