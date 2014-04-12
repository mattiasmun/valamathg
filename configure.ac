dnl Process this file with autoconf to produce a configure script.

AC_INIT(valamathg, 1.0)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 no-dist-gzip dist-xz foreign])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE
GNOME_MAINTAINER_MODE_DEFINES

AM_PROG_VALAC([0.24])
AM_PROG_CC_C_O

AC_PATH_PROG(GLIB_COMPILE_RESOURCES, glib-compile-resources)

GLIB_GSETTINGS

dnl ###########################################################################
dnl Dependencies
dnl ###########################################################################

GLIB_REQUIRED=2.31
GIO_REQUIRED=2.25.10
GTK_REQUIRED=3.10.7

PKG_CHECK_MODULES(VALAMATHG, [
    gtk+-3.0 >= $GTK_REQUIRED
    glib-2.0 >= $GLIB_REQUIRED
    gio-2.0 >= $GIO_REQUIRED
    gmodule-export-2.0
])
LT_INIT
AC_OUTPUT([
Makefile
])

