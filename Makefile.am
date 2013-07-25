EXTRA_DIST = autogen.sh valamathg.sh valamathg.vapi
AM_CPPFLAGS = $(VALAMATHG_CFLAGS)
ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -lm
AUTOMAKE_OPTIONS = dist-bzip2 no-dist-gzip

bin_PROGRAMS = valamathg
noinst_LTLIBRARIES = libvalamathg.la

libvalamathg_la_SOURCES = Elmnt.vala MyTimer.vala Operate.vala EventCog.vala ConfFile.vala MathCog.vala NumberUtils.vala
libvalamathg_la_VALAFLAGS = --pkg gtk+-3.0 --pkg gdk-3.0 --pkg gio-2.0 --library valamathg -H valamathg.h

valamathg_SOURCES = Frams.vala
valamathg_LDADD = libvalamathg.la $(VALAMATHG_LIBS)
valamathg_VALAFLAGS = --pkg gtk+-3.0 --pkg gdk-3.0 valamathg.vapi

CLEANFILES = *.c *.h *.stamp *.vapi

tbz2:
	tar -jcf valamathg.tbz2 AUTHORS autogen.sh ChangeLog configure.ac COPYING Makefile.am NEWS README *.c *.h *.stamp *.vala *.vapi
