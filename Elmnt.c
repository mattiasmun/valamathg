/* Elmnt.c generated by valac 0.22.1, the Vala compiler
 * generated from Elmnt.vala, do not modify */

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


#define MATHG_TYPE_ELMNT (mathg_elmnt_get_type ())
typedef struct _mathgElmnt mathgElmnt;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _mathgElmnt {
	gint64 answer;
	gchar* guess;
	gchar* question;
	gchar* result;
};



GType mathg_elmnt_get_type (void) G_GNUC_CONST;
mathgElmnt* mathg_elmnt_dup (const mathgElmnt* self);
void mathg_elmnt_free (mathgElmnt* self);
void mathg_elmnt_copy (const mathgElmnt* self, mathgElmnt* dest);
void mathg_elmnt_destroy (mathgElmnt* self);
void mathg_elmnt_init (mathgElmnt *self, gint64 a, const gchar* s);
gchar* mathg_elmnt_to_string (mathgElmnt *self);


void mathg_elmnt_init (mathgElmnt *self, gint64 a, const gchar* s) {
	gint64 _tmp0_ = 0LL;
	gchar* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_if_fail (s != NULL);
	memset (self, 0, sizeof (mathgElmnt));
	_tmp0_ = a;
	(*self).answer = _tmp0_;
	_tmp1_ = g_strdup ("");
	_g_free0 ((*self).guess);
	(*self).guess = _tmp1_;
	_tmp2_ = s;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 ((*self).question);
	(*self).question = _tmp3_;
}


gchar* mathg_elmnt_to_string (mathgElmnt *self) {
	gchar* result = NULL;
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	_tmp0_ = (*self).question;
	_tmp1_ = (*self).guess;
	_tmp2_ = g_strconcat (_tmp0_, _tmp1_, NULL);
	_tmp3_ = _tmp2_;
	_tmp4_ = (*self).result;
	_tmp5_ = g_strconcat (_tmp3_, _tmp4_, NULL);
	_tmp6_ = _tmp5_;
	_g_free0 (_tmp3_);
	result = _tmp6_;
	return result;
}


void mathg_elmnt_copy (const mathgElmnt* self, mathgElmnt* dest) {
	gint64 _tmp0_ = 0LL;
	const gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	_tmp0_ = (*self).answer;
	(*dest).answer = _tmp0_;
	_tmp1_ = (*self).guess;
	_tmp2_ = g_strdup (_tmp1_);
	_g_free0 ((*dest).guess);
	(*dest).guess = _tmp2_;
	_tmp3_ = (*self).question;
	_tmp4_ = g_strdup (_tmp3_);
	_g_free0 ((*dest).question);
	(*dest).question = _tmp4_;
	_tmp5_ = (*self).result;
	_tmp6_ = g_strdup (_tmp5_);
	_g_free0 ((*dest).result);
	(*dest).result = _tmp6_;
}


void mathg_elmnt_destroy (mathgElmnt* self) {
	_g_free0 ((*self).guess);
	_g_free0 ((*self).question);
	_g_free0 ((*self).result);
}


mathgElmnt* mathg_elmnt_dup (const mathgElmnt* self) {
	mathgElmnt* dup;
	dup = g_new0 (mathgElmnt, 1);
	mathg_elmnt_copy (self, dup);
	return dup;
}


void mathg_elmnt_free (mathgElmnt* self) {
	mathg_elmnt_destroy (self);
	g_free (self);
}


GType mathg_elmnt_get_type (void) {
	static volatile gsize mathg_elmnt_type_id__volatile = 0;
	if (g_once_init_enter (&mathg_elmnt_type_id__volatile)) {
		GType mathg_elmnt_type_id;
		mathg_elmnt_type_id = g_boxed_type_register_static ("mathgElmnt", (GBoxedCopyFunc) mathg_elmnt_dup, (GBoxedFreeFunc) mathg_elmnt_free);
		g_once_init_leave (&mathg_elmnt_type_id__volatile, mathg_elmnt_type_id);
	}
	return mathg_elmnt_type_id__volatile;
}



