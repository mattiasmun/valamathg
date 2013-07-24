/* NumberUtils.c generated by valac 0.18.1, the Vala compiler
 * generated from NumberUtils.vala, do not modify */

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
#include <float.h>
#include <math.h>


#define MATHG_TYPE_NUMBER_UTILS (mathg_number_utils_get_type ())
typedef struct _mathgNumberUtils mathgNumberUtils;
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _mathgNumberUtils {
	guint bas;
};



GType mathg_number_utils_get_type (void) G_GNUC_CONST;
mathgNumberUtils* mathg_number_utils_dup (const mathgNumberUtils* self);
void mathg_number_utils_free (mathgNumberUtils* self);
void mathg_number_utils_init (mathgNumberUtils *self, const gchar* s);
gint mathg_number_utils_ti (mathgNumberUtils *self, const gchar* a);
gdouble mathg_number_utils_td (mathgNumberUtils *self, const gchar* a);
gint64 mathg_number_utils_tl (mathgNumberUtils *self, const gchar* a);
gint64 g_ascii_strtoll (const gchar* nptr, gchar** endptr, guint _base);
gchar* mathg_number_utils_ts (mathgNumberUtils *self, gint64 a);
gchar* mathg_number_utils_uts (mathgNumberUtils *self, guint64 a);
#define MATHG_digits "0123456789abcdefghijklmnopqrstuvwxyz"


void mathg_number_utils_init (mathgNumberUtils *self, const gchar* s) {
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	g_return_if_fail (s != NULL);
	memset (self, 0, sizeof (mathgNumberUtils));
	(*self).bas = (guint) 10;
	_tmp0_ = s;
	_tmp1_ = mathg_number_utils_ti (&(*self), _tmp0_);
	(*self).bas = (guint) _tmp1_;
}


static gint string_index_of_char (const gchar* self, gunichar c, gint start_index) {
	gint result = 0;
	gint _tmp0_;
	gunichar _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _result_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = c;
	_tmp2_ = g_utf8_strchr (((gchar*) self) + _tmp0_, (gssize) (-1), _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


gdouble mathg_number_utils_td (mathgNumberUtils *self, const gchar* a) {
	gdouble result = 0.0;
	const gchar* _tmp0_;
	GString* _tmp1_;
	GString* sb;
	GString* _tmp2_;
	const gchar* _tmp3_;
	gint _tmp4_ = 0;
	gint i;
	gint _tmp5_;
	guint _tmp10_;
	GString* _tmp11_;
	gssize _tmp12_;
	gint _tmp13_;
	gdouble _tmp14_ = 0.0;
	gdouble d;
	GString* _tmp15_;
	const gchar* _tmp16_;
	gint64 _tmp17_ = 0LL;
	g_return_val_if_fail (a != NULL, 0.0);
	_tmp0_ = a;
	_tmp1_ = g_string_new (_tmp0_);
	sb = _tmp1_;
	_tmp2_ = sb;
	_tmp3_ = _tmp2_->str;
	_tmp4_ = string_index_of_char (_tmp3_, (gunichar) '.', 0);
	i = _tmp4_;
	_tmp5_ = i;
	if (_tmp5_ < 0) {
		GString* _tmp6_;
		gssize _tmp7_;
		_tmp6_ = sb;
		_tmp7_ = _tmp6_->len;
		i = (gint) _tmp7_;
	} else {
		GString* _tmp8_;
		gint _tmp9_;
		_tmp8_ = sb;
		_tmp9_ = i;
		g_string_erase (_tmp8_, (gssize) _tmp9_, (gssize) 1);
	}
	_tmp10_ = (*self).bas;
	_tmp11_ = sb;
	_tmp12_ = _tmp11_->len;
	_tmp13_ = i;
	_tmp14_ = pow ((gdouble) _tmp10_, (gdouble) (_tmp12_ - _tmp13_));
	d = _tmp14_;
	_tmp15_ = sb;
	_tmp16_ = _tmp15_->str;
	_tmp17_ = mathg_number_utils_tl (&(*self), _tmp16_);
	result = _tmp17_ / d;
	_g_string_free0 (sb);
	return result;
}


gint mathg_number_utils_ti (mathgNumberUtils *self, const gchar* a) {
	gint result = 0;
	const gchar* _tmp0_;
	gint64 _tmp1_ = 0LL;
	g_return_val_if_fail (a != NULL, 0);
	_tmp0_ = a;
	_tmp1_ = mathg_number_utils_tl (&(*self), _tmp0_);
	result = (gint) _tmp1_;
	return result;
}


gint64 mathg_number_utils_tl (mathgNumberUtils *self, const gchar* a) {
	gint64 result = 0LL;
	const gchar* _tmp0_;
	guint _tmp1_;
	gint64 _tmp2_ = 0LL;
	g_return_val_if_fail (a != NULL, 0LL);
	_tmp0_ = a;
	_tmp1_ = (*self).bas;
	_tmp2_ = g_ascii_strtoll (_tmp0_, NULL, _tmp1_);
	result = _tmp2_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


gchar* mathg_number_utils_ts (mathgNumberUtils *self, gint64 a) {
	gchar* result = NULL;
	gint64 _tmp0_;
	gboolean neg;
	gint64 _tmp1_;
	gint64 _tmp2_ = 0LL;
	gchar* _tmp3_ = NULL;
	gchar* s;
	gchar* _tmp4_ = NULL;
	gboolean _tmp5_;
	_tmp0_ = a;
	neg = _tmp0_ < ((gint64) 0);
	_tmp1_ = a;
	_tmp2_ = llabs (_tmp1_);
	_tmp3_ = mathg_number_utils_uts (&(*self), (guint64) _tmp2_);
	s = _tmp3_;
	_tmp5_ = neg;
	if (_tmp5_) {
		const gchar* _tmp6_;
		const gchar* _tmp7_ = NULL;
		gchar* _tmp8_ = NULL;
		_tmp6_ = s;
		_tmp7_ = string_to_string (_tmp6_);
		_tmp8_ = g_strconcat ("-", _tmp7_, NULL);
		_g_free0 (_tmp4_);
		_tmp4_ = _tmp8_;
	} else {
		const gchar* _tmp9_;
		gchar* _tmp10_;
		_tmp9_ = s;
		_tmp10_ = g_strdup (_tmp9_);
		_g_free0 (_tmp4_);
		_tmp4_ = _tmp10_;
	}
	result = _tmp4_;
	_g_free0 (s);
	return result;
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_;
	gchar _tmp1_;
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


gchar* mathg_number_utils_uts (mathgNumberUtils *self, guint64 a) {
	gchar* result = NULL;
	gboolean _tmp0_ = FALSE;
	guint _tmp1_;
	gboolean _tmp3_;
	GString* _tmp6_;
	GString* sb;
	guint rest;
	GString* _tmp17_;
	const gchar* _tmp18_;
	gchar* _tmp19_;
	_tmp1_ = (*self).bas;
	if (_tmp1_ == ((guint) 10)) {
		_tmp0_ = TRUE;
	} else {
		guint64 _tmp2_;
		_tmp2_ = a;
		_tmp0_ = _tmp2_ < ((guint64) 2);
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		guint64 _tmp4_;
		gchar* _tmp5_ = NULL;
		_tmp4_ = a;
		_tmp5_ = g_strdup_printf ("%" G_GUINT64_FORMAT, _tmp4_);
		result = _tmp5_;
		return result;
	}
	_tmp6_ = g_string_sized_new ((gsize) 64);
	sb = _tmp6_;
	rest = (guint) 0;
	{
		gboolean _tmp7_;
		_tmp7_ = TRUE;
		while (TRUE) {
			gboolean _tmp8_;
			guint64 _tmp11_;
			guint64 _tmp12_;
			guint _tmp13_;
			GString* _tmp14_;
			guint _tmp15_;
			gchar _tmp16_ = '\0';
			_tmp8_ = _tmp7_;
			if (!_tmp8_) {
				guint64 _tmp9_;
				guint _tmp10_;
				_tmp9_ = a;
				_tmp10_ = (*self).bas;
				a = _tmp9_ / _tmp10_;
			}
			_tmp7_ = FALSE;
			_tmp11_ = a;
			if (!(_tmp11_ > ((guint64) 0))) {
				break;
			}
			_tmp12_ = a;
			_tmp13_ = (*self).bas;
			rest = (guint) (_tmp12_ % _tmp13_);
			_tmp14_ = sb;
			_tmp15_ = rest;
			_tmp16_ = string_get (MATHG_digits, (glong) _tmp15_);
			g_string_prepend_c (_tmp14_, _tmp16_);
		}
	}
	_tmp17_ = sb;
	_tmp18_ = _tmp17_->str;
	_tmp19_ = g_strdup (_tmp18_);
	result = _tmp19_;
	_g_string_free0 (sb);
	return result;
}


mathgNumberUtils* mathg_number_utils_dup (const mathgNumberUtils* self) {
	mathgNumberUtils* dup;
	dup = g_new0 (mathgNumberUtils, 1);
	memcpy (dup, self, sizeof (mathgNumberUtils));
	return dup;
}


void mathg_number_utils_free (mathgNumberUtils* self) {
	g_free (self);
}


GType mathg_number_utils_get_type (void) {
	static volatile gsize mathg_number_utils_type_id__volatile = 0;
	if (g_once_init_enter (&mathg_number_utils_type_id__volatile)) {
		GType mathg_number_utils_type_id;
		mathg_number_utils_type_id = g_boxed_type_register_static ("mathgNumberUtils", (GBoxedCopyFunc) mathg_number_utils_dup, (GBoxedFreeFunc) mathg_number_utils_free);
		g_once_init_leave (&mathg_number_utils_type_id__volatile, mathg_number_utils_type_id);
	}
	return mathg_number_utils_type_id__volatile;
}



