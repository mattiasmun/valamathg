AC_PREREQ([2.65])
AC_INIT([valamathg],[1.0],[https://github.com/mattiasmun/valamathg])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE
AC_CONFIG_FILES([Makefile])

LT_INIT
AC_PROG_CC
AM_PROG_VALAC

pkg_modules="glib-2.0 >= 2.36.0
             gobject-2.0 >= 2.36.0
             gtk+-3.0 >= 3.6.4
             gdk-3.0 >= 3.6.4"
PKG_CHECK_MODULES(VALAMATHG, [$pkg_modules])
AC_SUBST(VALAMATHG_CFLAGS)
AC_SUBST(VALAMATHG_LIBS)

AC_OUTPUT
