/* EventCog.c generated by valac 0.20.1, the Vala compiler
 * generated from EventCog.vala, do not modify */

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
#include <gtk/gtk.h>
#include <float.h>
#include <math.h>
#include <gdk/gdk.h>


#define MATHG_TYPE_EVENT_COG (mathg_event_cog_get_type ())
#define MATHG_EVENT_COG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MATHG_TYPE_EVENT_COG, mathgEventCog))
#define MATHG_EVENT_COG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MATHG_TYPE_EVENT_COG, mathgEventCogClass))
#define MATHG_IS_EVENT_COG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MATHG_TYPE_EVENT_COG))
#define MATHG_IS_EVENT_COG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MATHG_TYPE_EVENT_COG))
#define MATHG_EVENT_COG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MATHG_TYPE_EVENT_COG, mathgEventCogClass))

typedef struct _mathgEventCog mathgEventCog;
typedef struct _mathgEventCogClass mathgEventCogClass;
typedef struct _mathgEventCogPrivate mathgEventCogPrivate;

#define MATHG_TYPE_MATH_COG (mathg_math_cog_get_type ())

#define MATHG_TYPE_NUMBER_UTILS (mathg_number_utils_get_type ())
typedef struct _mathgNumberUtils mathgNumberUtils;

#define MATHG_TYPE_OPERATE (mathg_operate_get_type ())
typedef struct _mathgOperate mathgOperate;

#define MATHG_TYPE_MY_TIMER (mathg_my_timer_get_type ())
typedef struct _mathgMyTimer mathgMyTimer;

#define MATHG_TYPE_ELMNT (mathg_elmnt_get_type ())
typedef struct _mathgElmnt mathgElmnt;
typedef struct _mathgMathCog mathgMathCog;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_regex_unref0(var) ((var == NULL) ? NULL : (var = (g_regex_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _mathgEventCog {
	GtkViewport parent_instance;
	mathgEventCogPrivate * priv;
};

struct _mathgEventCogClass {
	GtkViewportClass parent_class;
};

struct _mathgNumberUtils {
	guint bas;
};

struct _mathgOperate {
	gdouble min;
	gdouble span;
	gint term;
	gchar* type;
};

struct _mathgMyTimer {
	gboolean reset;
	GDateTime* start;
	GDateTime* stop;
};

struct _mathgElmnt {
	gint64 answer;
	gchar* guess;
	gchar* question;
	gchar* result;
};

struct _mathgMathCog {
	gchar* ch;
	guint64 cor;
	gdouble deviation;
	guint64 err;
	gboolean isenter;
	mathgNumberUtils nu;
	mathgOperate operation;
	gint pm;
	mathgMyTimer problem;
	gchar* res;
	mathgElmnt* stra;
	gint stra_length1;
	gint straind;
	mathgMyTimer total;
};

struct _mathgEventCogPrivate {
	gboolean ctrl;
	mathgMathCog mc;
	guint kod;
	GtkLabel** lb;
	gint lb_length1;
	gint _lb_size_;
};


static gpointer mathg_event_cog_parent_class = NULL;

GType mathg_event_cog_get_type (void) G_GNUC_CONST;
GType mathg_math_cog_get_type (void) G_GNUC_CONST;
GType mathg_number_utils_get_type (void) G_GNUC_CONST;
mathgNumberUtils* mathg_number_utils_dup (const mathgNumberUtils* self);
void mathg_number_utils_free (mathgNumberUtils* self);
GType mathg_operate_get_type (void) G_GNUC_CONST;
mathgOperate* mathg_operate_dup (const mathgOperate* self);
void mathg_operate_free (mathgOperate* self);
void mathg_operate_copy (const mathgOperate* self, mathgOperate* dest);
void mathg_operate_destroy (mathgOperate* self);
GType mathg_my_timer_get_type (void) G_GNUC_CONST;
mathgMyTimer* mathg_my_timer_dup (const mathgMyTimer* self);
void mathg_my_timer_free (mathgMyTimer* self);
void mathg_my_timer_copy (const mathgMyTimer* self, mathgMyTimer* dest);
void mathg_my_timer_destroy (mathgMyTimer* self);
GType mathg_elmnt_get_type (void) G_GNUC_CONST;
mathgElmnt* mathg_elmnt_dup (const mathgElmnt* self);
void mathg_elmnt_free (mathgElmnt* self);
void mathg_elmnt_copy (const mathgElmnt* self, mathgElmnt* dest);
void mathg_elmnt_destroy (mathgElmnt* self);
mathgMathCog* mathg_math_cog_dup (const mathgMathCog* self);
void mathg_math_cog_free (mathgMathCog* self);
void mathg_math_cog_copy (const mathgMathCog* self, mathgMathCog* dest);
void mathg_math_cog_destroy (mathgMathCog* self);
#define MATHG_EVENT_COG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MATHG_TYPE_EVENT_COG, mathgEventCogPrivate))
enum  {
	MATHG_EVENT_COG_DUMMY_PROPERTY
};
mathgEventCog* mathg_event_cog_new (gchar** args, int args_length1);
mathgEventCog* mathg_event_cog_construct (GType object_type, gchar** args, int args_length1);
void mathg_math_cog_init (mathgMathCog *self, gchar** args, int args_length1);
static void mathg_event_cog_caseixy (mathgEventCog* self, gint i);
gchar* mathg_elmnt_to_string (mathgElmnt *self);
static gboolean mathg_event_cog_is_ctrl (mathgEventCog* self);
static gboolean mathg_event_cog_is_enter (mathgEventCog* self);
static gboolean mathg_event_cog_real_key_press_event (GtkWidget* base, GdkEventKey* event);
void mathg_math_cog_bsp (mathgMathCog *self);
void mathg_math_cog_generate (mathgMathCog *self);
void mathg_math_cog_put (mathgMathCog *self);
void mathg_event_cog_repaint (mathgEventCog* self);
static gboolean mathg_event_cog_real_key_release_event (GtkWidget* base, GdkEventKey* event);
static gboolean mathg_event_cog_real_scroll_event (GtkWidget* base, GdkEventScroll* event);
static void mathg_event_cog_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);

const gchar* MATHG_sa[4] = {"xx-large", "x-large", "large", "medium"};

mathgEventCog* mathg_event_cog_construct (GType object_type, gchar** args, int args_length1) {
	mathgEventCog * self = NULL;
	GtkGrid* _tmp0_;
	GtkGrid* g;
	GtkLabel** _tmp1_ = NULL;
	GtkGrid* _tmp18_;
	gchar** _tmp19_;
	gint _tmp19__length1;
	self = (mathgEventCog*) g_object_new (object_type, NULL);
	_tmp0_ = (GtkGrid*) gtk_grid_new ();
	g_object_ref_sink (_tmp0_);
	g = _tmp0_;
	_tmp1_ = g_new0 (GtkLabel*, 8 + 1);
	self->priv->lb = (_vala_array_free (self->priv->lb, self->priv->lb_length1, (GDestroyNotify) g_object_unref), NULL);
	self->priv->lb = _tmp1_;
	self->priv->lb_length1 = 8;
	self->priv->_lb_size_ = self->priv->lb_length1;
	{
		gint i;
		i = 0;
		{
			gboolean _tmp2_;
			_tmp2_ = TRUE;
			while (TRUE) {
				gboolean _tmp3_;
				gint _tmp5_;
				GtkLabel** _tmp6_;
				gint _tmp6__length1;
				gint _tmp7_;
				gint _tmp8_;
				gchar* _tmp9_ = NULL;
				gchar* _tmp10_;
				GtkLabel* _tmp11_;
				GtkLabel* _tmp12_;
				GtkGrid* _tmp13_;
				GtkLabel** _tmp14_;
				gint _tmp14__length1;
				gint _tmp15_;
				GtkLabel* _tmp16_;
				gint _tmp17_;
				_tmp3_ = _tmp2_;
				if (!_tmp3_) {
					gint _tmp4_;
					_tmp4_ = i;
					i = _tmp4_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp5_ = i;
				if (!(_tmp5_ < 8)) {
					break;
				}
				_tmp6_ = self->priv->lb;
				_tmp6__length1 = self->priv->lb_length1;
				_tmp7_ = i;
				_tmp8_ = i;
				_tmp9_ = g_strdup_printf ("%i", _tmp8_);
				_tmp10_ = _tmp9_;
				_tmp11_ = (GtkLabel*) gtk_label_new (_tmp10_);
				g_object_ref_sink (_tmp11_);
				_g_object_unref0 (_tmp6_[_tmp7_]);
				_tmp6_[_tmp7_] = _tmp11_;
				_tmp12_ = _tmp6_[_tmp7_];
				_g_free0 (_tmp10_);
				_tmp13_ = g;
				_tmp14_ = self->priv->lb;
				_tmp14__length1 = self->priv->lb_length1;
				_tmp15_ = i;
				_tmp16_ = _tmp14_[_tmp15_];
				_tmp17_ = i;
				gtk_grid_attach (_tmp13_, (GtkWidget*) _tmp16_, 1, _tmp17_, 1, 1);
			}
		}
	}
	_tmp18_ = g;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp18_);
	_tmp19_ = args;
	_tmp19__length1 = args_length1;
	mathg_math_cog_destroy (&self->priv->mc);
	mathg_math_cog_init (&self->priv->mc, _tmp19_, _tmp19__length1);
	g_object_set ((GtkWidget*) self, "can-focus", TRUE, NULL);
	gtk_widget_grab_focus ((GtkWidget*) self);
	_g_object_unref0 (g);
	return self;
}


mathgEventCog* mathg_event_cog_new (gchar** args, int args_length1) {
	return mathg_event_cog_construct (MATHG_TYPE_EVENT_COG, args, args_length1);
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void mathg_event_cog_caseixy (mathgEventCog* self, gint i) {
	mathgMathCog _tmp0_;
	gint _tmp1_;
	gint _tmp2_;
	gint j;
	gboolean _tmp3_ = FALSE;
	mathgMathCog _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	gboolean _tmp10_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->mc;
	_tmp1_ = _tmp0_.straind;
	_tmp2_ = i;
	j = (_tmp1_ + _tmp2_) - 3;
	_tmp4_ = self->priv->mc;
	_tmp5_ = _tmp4_.straind;
	_tmp6_ = i;
	if ((_tmp5_ + _tmp6_) > 2) {
		gint _tmp7_;
		mathgMathCog _tmp8_;
		mathgElmnt* _tmp9_;
		gint _tmp9__length1;
		_tmp7_ = j;
		_tmp8_ = self->priv->mc;
		_tmp9_ = _tmp8_.stra;
		_tmp9__length1 = _tmp8_.stra_length1;
		_tmp3_ = _tmp7_ < _tmp9__length1;
	} else {
		_tmp3_ = FALSE;
	}
	_tmp10_ = _tmp3_;
	if (_tmp10_) {
		gint _tmp11_;
		gint _tmp12_ = 0;
		const gchar* _tmp13_;
		const gchar* _tmp14_ = NULL;
		gchar* _tmp15_ = NULL;
		gchar* s;
		const gchar* _tmp16_;
		const gchar* _tmp17_ = NULL;
		mathgMathCog _tmp18_;
		mathgElmnt* _tmp19_;
		gint _tmp19__length1;
		gint _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* _tmp22_;
		gchar* _tmp23_ = NULL;
		GtkLabel** _tmp24_;
		gint _tmp24__length1;
		gint _tmp25_;
		GtkLabel* _tmp26_;
		const gchar* _tmp27_;
		_tmp11_ = i;
		_tmp12_ = abs (_tmp11_ - 3);
		_tmp13_ = MATHG_sa[_tmp12_];
		_tmp14_ = string_to_string (_tmp13_);
		_tmp15_ = g_strconcat ("<span size=\"", _tmp14_, "\">", NULL);
		s = _tmp15_;
		_tmp16_ = s;
		_tmp17_ = string_to_string (_tmp16_);
		_tmp18_ = self->priv->mc;
		_tmp19_ = _tmp18_.stra;
		_tmp19__length1 = _tmp18_.stra_length1;
		_tmp20_ = j;
		_tmp21_ = mathg_elmnt_to_string (&_tmp19_[_tmp20_]);
		_tmp22_ = _tmp21_;
		_tmp23_ = g_strconcat (_tmp17_, _tmp22_, "</span>", NULL);
		_g_free0 (s);
		s = _tmp23_;
		_g_free0 (_tmp22_);
		_tmp24_ = self->priv->lb;
		_tmp24__length1 = self->priv->lb_length1;
		_tmp25_ = i;
		_tmp26_ = _tmp24_[_tmp25_];
		_tmp27_ = s;
		gtk_label_set_markup (_tmp26_, _tmp27_);
		_g_free0 (s);
	} else {
		GtkLabel** _tmp28_;
		gint _tmp28__length1;
		gint _tmp29_;
		GtkLabel* _tmp30_;
		_tmp28_ = self->priv->lb;
		_tmp28__length1 = self->priv->lb_length1;
		_tmp29_ = i;
		_tmp30_ = _tmp28_[_tmp29_];
		gtk_label_set_text (_tmp30_, "");
	}
}


static gboolean mathg_event_cog_is_ctrl (mathgEventCog* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	guint _tmp1_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = self->priv->kod;
	if (_tmp1_ == ((guint) GDK_KEY_Control_L)) {
		_tmp0_ = TRUE;
	} else {
		guint _tmp2_;
		_tmp2_ = self->priv->kod;
		_tmp0_ = _tmp2_ == ((guint) GDK_KEY_Control_R);
	}
	_tmp3_ = _tmp0_;
	result = _tmp3_;
	return result;
}


static gboolean mathg_event_cog_is_enter (mathgEventCog* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	guint _tmp1_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = self->priv->kod;
	if (_tmp1_ == ((guint) GDK_KEY_KP_Enter)) {
		_tmp0_ = TRUE;
	} else {
		guint _tmp2_;
		_tmp2_ = self->priv->kod;
		_tmp0_ = _tmp2_ == ((guint) GDK_KEY_Return);
	}
	_tmp3_ = _tmp0_;
	result = _tmp3_;
	return result;
}


static gchar* string_replace (const gchar* self, const gchar* old, const gchar* replacement) {
	gchar* result = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (old != NULL, NULL);
	g_return_val_if_fail (replacement != NULL, NULL);
	{
		const gchar* _tmp0_;
		gchar* _tmp1_ = NULL;
		gchar* _tmp2_;
		GRegex* _tmp3_;
		GRegex* _tmp4_;
		GRegex* regex;
		GRegex* _tmp5_;
		const gchar* _tmp6_;
		gchar* _tmp7_ = NULL;
		gchar* _tmp8_;
		_tmp0_ = old;
		_tmp1_ = g_regex_escape_string (_tmp0_, -1);
		_tmp2_ = _tmp1_;
		_tmp3_ = g_regex_new (_tmp2_, 0, 0, &_inner_error_);
		_tmp4_ = _tmp3_;
		_g_free0 (_tmp2_);
		regex = _tmp4_;
		if (_inner_error_ != NULL) {
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp5_ = regex;
		_tmp6_ = replacement;
		_tmp7_ = g_regex_replace_literal (_tmp5_, self, (gssize) (-1), 0, _tmp6_, 0, &_inner_error_);
		_tmp8_ = _tmp7_;
		if (_inner_error_ != NULL) {
			_g_regex_unref0 (regex);
			if (_inner_error_->domain == G_REGEX_ERROR) {
				goto __catch0_g_regex_error;
			}
			_g_regex_unref0 (regex);
			g_critical ("file %s: line %d: unexpected error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		result = _tmp8_;
		_g_regex_unref0 (regex);
		return result;
	}
	goto __finally0;
	__catch0_g_regex_error:
	{
		GError* e = NULL;
		e = _inner_error_;
		_inner_error_ = NULL;
		g_assert_not_reached ();
		_g_error_free0 (e);
	}
	__finally0:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
}


static gboolean mathg_event_cog_real_key_press_event (GtkWidget* base, GdkEventKey* event) {
	mathgEventCog * self;
	gboolean result = FALSE;
	GdkEventKey _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	GdkEventKey _tmp3_;
	guint _tmp4_;
	gboolean _tmp5_ = FALSE;
	guint _tmp6_;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	gboolean _tmp12_;
	mathgMathCog _tmp13_;
	mathgElmnt* _tmp14_;
	gint _tmp14__length1;
	mathgMathCog _tmp15_;
	gint _tmp16_;
	mathgElmnt _tmp17_;
	const gchar* _tmp18_;
	self = (mathgEventCog*) base;
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = *event;
	_tmp1_ = _tmp0_.string;
	_tmp2_ = string_replace (_tmp1_, "§", "0");
	_g_free0 (self->priv->mc.ch);
	self->priv->mc.ch = _tmp2_;
	_tmp3_ = *event;
	_tmp4_ = _tmp3_.keyval;
	self->priv->kod = _tmp4_;
	_tmp5_ = mathg_event_cog_is_enter (self);
	self->priv->mc.isenter = _tmp5_;
	_tmp6_ = self->priv->kod;
	switch (_tmp6_) {
		case GDK_KEY_BackSpace:
		{
			mathg_math_cog_bsp (&self->priv->mc);
			break;
		}
		case GDK_KEY_Q:
		case GDK_KEY_q:
		{
			gboolean _tmp7_;
			_tmp7_ = self->priv->ctrl;
			if (_tmp7_) {
				gtk_main_quit ();
			}
			break;
		}
		case GDK_KEY_R:
		case GDK_KEY_r:
		{
			gboolean _tmp8_;
			_tmp8_ = self->priv->ctrl;
			if (_tmp8_) {
				mathg_math_cog_generate (&self->priv->mc);
			}
			break;
		}
		default:
		break;
	}
	_tmp10_ = mathg_event_cog_is_ctrl (self);
	if (_tmp10_) {
		_tmp9_ = TRUE;
	} else {
		gboolean _tmp11_;
		_tmp11_ = self->priv->ctrl;
		_tmp9_ = _tmp11_;
	}
	_tmp12_ = _tmp9_;
	self->priv->ctrl = _tmp12_;
	_tmp13_ = self->priv->mc;
	_tmp14_ = _tmp13_.stra;
	_tmp14__length1 = _tmp13_.stra_length1;
	_tmp15_ = self->priv->mc;
	_tmp16_ = _tmp15_.straind;
	_tmp17_ = _tmp14_[_tmp16_];
	_tmp18_ = _tmp17_.result;
	if (_tmp18_ == NULL) {
		mathg_math_cog_put (&self->priv->mc);
	}
	mathg_event_cog_repaint (self);
	result = TRUE;
	return result;
}


static gboolean mathg_event_cog_real_key_release_event (GtkWidget* base, GdkEventKey* event) {
	mathgEventCog * self;
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	gboolean _tmp3_;
	self = (mathgEventCog*) base;
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp1_ = mathg_event_cog_is_ctrl (self);
	if (_tmp1_) {
		_tmp0_ = FALSE;
	} else {
		gboolean _tmp2_;
		_tmp2_ = self->priv->ctrl;
		_tmp0_ = _tmp2_;
	}
	_tmp3_ = _tmp0_;
	self->priv->ctrl = _tmp3_;
	result = TRUE;
	return result;
}


void mathg_event_cog_repaint (mathgEventCog* self) {
	GtkLabel** _tmp5_;
	gint _tmp5__length1;
	GtkLabel* _tmp6_;
	mathgMathCog _tmp7_;
	const gchar* _tmp8_;
	g_return_if_fail (self != NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				gint _tmp3_;
				gint _tmp4_;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = i;
				if (!(_tmp3_ < 7)) {
					break;
				}
				_tmp4_ = i;
				mathg_event_cog_caseixy (self, _tmp4_);
			}
		}
	}
	_tmp5_ = self->priv->lb;
	_tmp5__length1 = self->priv->lb_length1;
	_tmp6_ = _tmp5_[7];
	_tmp7_ = self->priv->mc;
	_tmp8_ = _tmp7_.res;
	gtk_label_set_text (_tmp6_, _tmp8_);
}


static gboolean mathg_event_cog_real_scroll_event (GtkWidget* base, GdkEventScroll* event) {
	mathgEventCog * self;
	gboolean result = FALSE;
	GdkEventScroll _tmp0_;
	gdouble _tmp1_;
	gint scr;
	gint _tmp2_ = 0;
	gboolean _tmp3_ = FALSE;
	mathgMathCog _tmp4_;
	gint _tmp5_;
	gint _tmp6_;
	mathgMathCog _tmp7_;
	mathgElmnt* _tmp8_;
	gint _tmp8__length1;
	gboolean _tmp12_;
	gint _tmp14_;
	gint _tmp15_;
	self = (mathgEventCog*) base;
	g_return_val_if_fail (event != NULL, FALSE);
	_tmp0_ = *event;
	_tmp1_ = _tmp0_.delta_y;
	scr = (gint) _tmp1_;
	_tmp4_ = self->priv->mc;
	_tmp5_ = _tmp4_.straind;
	_tmp6_ = scr;
	_tmp7_ = self->priv->mc;
	_tmp8_ = _tmp7_.stra;
	_tmp8__length1 = _tmp7_.stra_length1;
	if ((_tmp5_ + _tmp6_) < _tmp8__length1) {
		mathgMathCog _tmp9_;
		gint _tmp10_;
		gint _tmp11_;
		_tmp9_ = self->priv->mc;
		_tmp10_ = _tmp9_.straind;
		_tmp11_ = scr;
		_tmp3_ = (_tmp10_ + _tmp11_) >= 0;
	} else {
		_tmp3_ = FALSE;
	}
	_tmp12_ = _tmp3_;
	if (_tmp12_) {
		gint _tmp13_;
		_tmp13_ = scr;
		_tmp2_ = _tmp13_;
	} else {
		_tmp2_ = 0;
	}
	_tmp14_ = self->priv->mc.straind;
	_tmp15_ = _tmp2_;
	self->priv->mc.straind = _tmp14_ + _tmp15_;
	mathg_event_cog_repaint (self);
	result = TRUE;
	return result;
}


static void mathg_event_cog_class_init (mathgEventCogClass * klass) {
	mathg_event_cog_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (mathgEventCogPrivate));
	GTK_WIDGET_CLASS (klass)->key_press_event = mathg_event_cog_real_key_press_event;
	GTK_WIDGET_CLASS (klass)->key_release_event = mathg_event_cog_real_key_release_event;
	GTK_WIDGET_CLASS (klass)->scroll_event = mathg_event_cog_real_scroll_event;
	G_OBJECT_CLASS (klass)->finalize = mathg_event_cog_finalize;
}


static void mathg_event_cog_instance_init (mathgEventCog * self) {
	self->priv = MATHG_EVENT_COG_GET_PRIVATE (self);
	self->priv->ctrl = FALSE;
}


static void mathg_event_cog_finalize (GObject* obj) {
	mathgEventCog * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, MATHG_TYPE_EVENT_COG, mathgEventCog);
	mathg_math_cog_destroy (&self->priv->mc);
	self->priv->lb = (_vala_array_free (self->priv->lb, self->priv->lb_length1, (GDestroyNotify) g_object_unref), NULL);
	G_OBJECT_CLASS (mathg_event_cog_parent_class)->finalize (obj);
}


GType mathg_event_cog_get_type (void) {
	static volatile gsize mathg_event_cog_type_id__volatile = 0;
	if (g_once_init_enter (&mathg_event_cog_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (mathgEventCogClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) mathg_event_cog_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (mathgEventCog), 0, (GInstanceInitFunc) mathg_event_cog_instance_init, NULL };
		GType mathg_event_cog_type_id;
		mathg_event_cog_type_id = g_type_register_static (GTK_TYPE_VIEWPORT, "mathgEventCog", &g_define_type_info, 0);
		g_once_init_leave (&mathg_event_cog_type_id__volatile, mathg_event_cog_type_id);
	}
	return mathg_event_cog_type_id__volatile;
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



