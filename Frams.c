/* Frams.c generated by valac 0.22.1, the Vala compiler
 * generated from Frams.vala, do not modify */

/*Copyright (C) 2013 Mattias Münster

Author: Mattias Münster <mattiasmun@gmail.com>

This file is part of valamathg.

valamathg is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

valamathg is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with valamathg.  If not, see <http://www.gnu.org/licenses/>.*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include "valamathg.h"
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))



void _vala_main (gchar** args, int args_length1);
static gchar** _vala_array_dup1 (gchar** self, int length);
static gchar** _vala_array_dup2 (gchar** self, int length);
void frame (GtkWindow* gw, gchar** args, int args_length1);
static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


static gchar** _vala_array_dup1 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_ = NULL;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


static gchar** _vala_array_dup2 (gchar** self, int length) {
	gchar** result;
	int i;
	result = g_new0 (gchar*, length + 1);
	for (i = 0; i < length; i++) {
		gchar* _tmp0_ = NULL;
		_tmp0_ = g_strdup (self[i]);
		result[i] = _tmp0_;
	}
	return result;
}


void _vala_main (gchar** args, int args_length1) {
	gchar** _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint __tmp0__size_ = 0;
	gchar** _tmp1_ = NULL;
	gint _tmp1__length1 = 0;
	gchar** data = NULL;
	gchar** _tmp9_ = NULL;
	gint _tmp9__length1 = 0;
	gchar** _tmp10_ = NULL;
	gint _tmp10__length1 = 0;
	gint data_length1 = 0;
	gint _data_size_ = 0;
	GtkWindow* gw = NULL;
	GtkWindow* _tmp11_ = NULL;
	_tmp1_ = args;
	_tmp1__length1 = args_length1;
	if (_tmp1__length1 == 8) {
		gchar** _tmp2_ = NULL;
		gint _tmp2__length1 = 0;
		gchar** _tmp3_ = NULL;
		gint _tmp3__length1 = 0;
		gchar** _tmp4_ = NULL;
		gint _tmp4__length1 = 0;
		_tmp2_ = args;
		_tmp2__length1 = args_length1;
		_tmp3_ = args;
		_tmp3__length1 = args_length1;
		_tmp4_ = ((_tmp2_ + 1) != NULL) ? _vala_array_dup1 (_tmp2_ + 1, _tmp3__length1 - 1) : ((gpointer) (_tmp2_ + 1));
		_tmp4__length1 = _tmp3__length1 - 1;
		_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
		_tmp0_ = _tmp4_;
		_tmp0__length1 = _tmp4__length1;
		__tmp0__size_ = _tmp0__length1;
	} else {
		mathgConfFile _tmp5_ = {0};
		mathgConfFile _tmp6_ = {0};
		gint _tmp7_ = 0;
		gchar** _tmp8_ = NULL;
		mathg_conf_file_init (&_tmp5_);
		_tmp6_ = _tmp5_;
		_tmp8_ = mathg_conf_file_tryread (&_tmp6_, &_tmp7_);
		_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
		_tmp0_ = _tmp8_;
		_tmp0__length1 = _tmp7_;
		__tmp0__size_ = _tmp0__length1;
		mathg_conf_file_destroy (&_tmp6_);
	}
	_tmp9_ = _tmp0_;
	_tmp9__length1 = _tmp0__length1;
	_tmp10_ = (_tmp9_ != NULL) ? _vala_array_dup2 (_tmp9_, _tmp9__length1) : ((gpointer) _tmp9_);
	_tmp10__length1 = _tmp9__length1;
	data = _tmp10_;
	data_length1 = _tmp10__length1;
	_data_size_ = data_length1;
	gtk_init (&args_length1, &args);
	_tmp11_ = (GtkWindow*) gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_object_ref_sink (_tmp11_);
	gw = _tmp11_;
	frame (gw, data, data_length1);
	gtk_main ();
	_g_object_unref0 (gw);
	data = (_vala_array_free (data, data_length1, (GDestroyNotify) g_free), NULL);
	_tmp0_ = (_vala_array_free (_tmp0_, _tmp0__length1, (GDestroyNotify) g_free), NULL);
}


int main (int argc, char ** argv) {
	g_type_init ();
	_vala_main (argv, argc);
	return 0;
}


static void _gtk_main_quit_gtk_widget_destroy (GtkWidget* _sender, gpointer self) {
	gtk_main_quit ();
}


void frame (GtkWindow* gw, gchar** args, int args_length1) {
	GtkWindow* _tmp0_ = NULL;
	GtkWindow* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	GtkWindow* _tmp3_ = NULL;
	mathgEventCog* ec = NULL;
	gchar** _tmp4_ = NULL;
	gint _tmp4__length1 = 0;
	mathgEventCog* _tmp5_ = NULL;
	GtkWindow* _tmp6_ = NULL;
	GtkWindow* _tmp7_ = NULL;
	g_return_if_fail (gw != NULL);
	_tmp0_ = gw;
	gtk_window_set_title (_tmp0_, "valamathg");
	_tmp1_ = gw;
	_tmp2_ = gdk_screen_width ();
	gtk_window_set_default_size (_tmp1_, _tmp2_, 106);
	_tmp3_ = gw;
	g_signal_connect ((GtkWidget*) _tmp3_, "destroy", (GCallback) _gtk_main_quit_gtk_widget_destroy, NULL);
	_tmp4_ = args;
	_tmp4__length1 = args_length1;
	_tmp5_ = mathg_event_cog_new (_tmp4_, _tmp4__length1);
	g_object_ref_sink (_tmp5_);
	ec = _tmp5_;
	_tmp6_ = gw;
	gtk_container_add ((GtkContainer*) _tmp6_, (GtkWidget*) ec);
	_tmp7_ = gw;
	gtk_widget_show_all ((GtkWidget*) _tmp7_);
	mathg_event_cog_repaint (ec);
	_g_object_unref0 (ec);
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}



