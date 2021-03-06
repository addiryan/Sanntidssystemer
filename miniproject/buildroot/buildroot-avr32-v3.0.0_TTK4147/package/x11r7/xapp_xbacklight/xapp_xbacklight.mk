################################################################################
#
# xapp_backlight -- xbacklight
#
################################################################################

XAPP_XBACKLIGHT_VERSION = 1.1.1
XAPP_XBACKLIGHT_SOURCE = xbacklight-$(XAPP_XBACKLIGHT_VERSION).tar.bz2
XAPP_XBACKLIGHT_SITE = http://xorg.freedesktop.org/releases/individual/app
XAPP_XBACKLIGHT_AUTORECONF = NO
XAPP_XBACKLIGHT_DEPENDENCIES = xlib_libX11

$(eval $(call AUTOTARGETS,package/x11r7,xapp_xbacklight))
