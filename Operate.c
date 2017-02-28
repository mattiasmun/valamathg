/* Operate.c generated by valac 0.34.4, the Vala compiler
 * generated from Operate.vala, do not modify */

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


#define MATHG_TYPE_OPERATE (mathg_operate_get_type ())
typedef struct _mathgOperate mathgOperate;
#define _g_free0(var) (var = (g_free (var), NULL))

#define MATHG_TYPE_MATH_COG (mathg_math_cog_get_type ())

#define MATHG_TYPE_NUMBER_UTILS (mathg_number_utils_get_type ())
typedef struct _mathgNumberUtils mathgNumberUtils;

#define MATHG_TYPE_MY_TIMER (mathg_my_timer_get_type ())
typedef struct _mathgMyTimer mathgMyTimer;

#define MATHG_TYPE_ELMNT (mathg_elmnt_get_type ())
typedef struct _mathgElmnt mathgElmnt;
typedef struct _mathgMathCog mathgMathCog;
#define _vala_assert(expr, msg) if G_LIKELY (expr) ; else g_assertion_message_expr (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);
#define _vala_return_if_fail(expr, msg) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return; }
#define _vala_return_val_if_fail(expr, msg, val) if G_LIKELY (expr) ; else { g_return_if_fail_warning (G_LOG_DOMAIN, G_STRFUNC, msg); return val; }
#define _vala_warn_if_fail(expr, msg) if G_LIKELY (expr) ; else g_warn_message (G_LOG_DOMAIN, __FILE__, __LINE__, G_STRFUNC, msg);

struct _mathgOperate {
	gdouble min;
	gdouble span;
	gint term;
	gchar* type;
};

struct _mathgNumberUtils {
	gint bas;
};

struct _mathgMyTimer {
	gboolean reset;
	GDateTime* start;
	GDateTime* stop;
};

struct _mathgElmnt {
	gdouble answer;
	gchar* guess;
	gchar* question;
	gchar* result;
};

struct _mathgMathCog {
	gchar* ch;
	gdouble cor;
	gdouble deviation;
	gdouble err;
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



#define MATHG_types "+-x/"
GType mathg_operate_get_type (void) G_GNUC_CONST;
mathgOperate* mathg_operate_dup (const mathgOperate* self);
void mathg_operate_free (mathgOperate* self);
void mathg_operate_copy (const mathgOperate* self, mathgOperate* dest);
void mathg_operate_destroy (mathgOperate* self);
void mathg_operate_init (mathgOperate *self, gdouble a, gdouble b, const gchar* c, gint d);
static gchar* mathg_operate_checktype (mathgOperate *self, const gchar* s);
GType mathg_math_cog_get_type (void) G_GNUC_CONST;
GType mathg_number_utils_get_type (void) G_GNUC_CONST;
mathgNumberUtils* mathg_number_utils_dup (const mathgNumberUtils* self);
void mathg_number_utils_free (mathgNumberUtils* self);
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
void mathg_operate_oper (mathgOperate *self, mathgMathCog* mc, gint i);
static gdouble mathg_operate_rand (mathgOperate *self);
gchar* mathg_number_utils_ts (mathgNumberUtils *self, gdouble d);
static gdouble mathg_operate_sumup (mathgOperate *self, gdouble* numa, int numa_length1, gchar* typea, int typea_length1);
void mathg_elmnt_init (mathgElmnt *self, gdouble a, const gchar* s);


void mathg_operate_init (mathgOperate *self, gdouble a, gdouble b, const gchar* c, gint d) {
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gdouble _tmp2_ = 0.0;
	gdouble _tmp3_ = 0.0;
	gdouble _tmp4_ = 0.0;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gint _tmp7_ = 0;
	g_return_if_fail (c != NULL);
	memset (self, 0, sizeof (mathgOperate));
	_tmp0_ = a;
	_tmp1_ = log (_tmp0_);
	(*self).min = _tmp1_;
	_tmp2_ = b;
	_tmp3_ = log (_tmp2_);
	_tmp4_ = (*self).min;
	(*self).span = _tmp3_ - _tmp4_;
	_tmp5_ = c;
	_tmp6_ = mathg_operate_checktype (&(*self), _tmp5_);
	_g_free0 ((*self).type);
	(*self).type = _tmp6_;
	_tmp7_ = d;
	(*self).term = _tmp7_;
}


static gint string_index_of_char (const gchar* self, gunichar c, gint start_index) {
	gint result = 0;
	gchar* _result_ = NULL;
	gint _tmp0_ = 0;
	gunichar _tmp1_ = 0U;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = c;
	_tmp2_ = g_utf8_strchr (((gchar*) self) + _tmp0_, (gssize) -1, _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_ = NULL;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


static gchar string_get (const gchar* self, glong index) {
	gchar result = '\0';
	glong _tmp0_ = 0L;
	gchar _tmp1_ = '\0';
	g_return_val_if_fail (self != NULL, '\0');
	_tmp0_ = index;
	_tmp1_ = ((gchar*) self)[_tmp0_];
	result = _tmp1_;
	return result;
}


static gchar* mathg_operate_checktype (mathgOperate *self, const gchar* s) {
	gchar* result = NULL;
	const gchar* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	g_return_val_if_fail (s != NULL, NULL);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gint _tmp2_ = 0;
				const gchar* _tmp3_ = NULL;
				gint _tmp4_ = 0;
				gint _tmp5_ = 0;
				const gchar* _tmp6_ = NULL;
				gint _tmp7_ = 0;
				gchar _tmp8_ = '\0';
				gint _tmp9_ = 0;
				if (!_tmp0_) {
					gint _tmp1_ = 0;
					_tmp1_ = i;
					i = _tmp1_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp2_ = i;
				_tmp3_ = s;
				_tmp4_ = strlen (_tmp3_);
				_tmp5_ = _tmp4_;
				if (!(_tmp2_ < _tmp5_)) {
					break;
				}
				_tmp6_ = s;
				_tmp7_ = i;
				_tmp8_ = string_get (_tmp6_, (glong) _tmp7_);
				_tmp9_ = string_index_of_char (MATHG_types, (gunichar) _tmp8_, 0);
				_vala_assert (_tmp9_ > -1, "types.index_of_char(s[i]) > -1");
			}
		}
	}
	_tmp10_ = s;
	_tmp11_ = g_strdup (_tmp10_);
	result = _tmp11_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void mathg_operate_oper (mathgOperate *self, mathgMathCog* mc, gint i) {
	gdouble* ia = NULL;
	gint _tmp0_ = 0;
	gdouble* _tmp1_ = NULL;
	gint ia_length1 = 0;
	gint _ia_size_ = 0;
	gdouble* tmpa = NULL;
	gint _tmp2_ = 0;
	gdouble* _tmp3_ = NULL;
	gint tmpa_length1 = 0;
	gint _tmpa_size_ = 0;
	gchar* ca = NULL;
	gint _tmp15_ = 0;
	gchar* _tmp16_ = NULL;
	gint ca_length1 = 0;
	gint _ca_size_ = 0;
	gint div = 0;
	gint mul = 0;
	gint oth = 0;
	gchar* q = NULL;
	gint _tmp62_ = 0;
	gchar* _tmp63_ = NULL;
	gchar* _tmp64_ = NULL;
	gdouble* _tmp65_ = NULL;
	gint _tmp65__length1 = 0;
	gdouble _tmp66_ = 0.0;
	gchar* _tmp67_ = NULL;
	gchar* _tmp68_ = NULL;
	const gchar* _tmp69_ = NULL;
	gchar* _tmp70_ = NULL;
	gchar* _tmp71_ = NULL;
	gint _tmp91_ = 0;
	gdouble* _tmp92_ = NULL;
	gint _tmp92__length1 = 0;
	gchar* _tmp93_ = NULL;
	gint _tmp93__length1 = 0;
	gdouble _tmp94_ = 0.0;
	const gchar* _tmp95_ = NULL;
	const gchar* _tmp96_ = NULL;
	gchar* _tmp97_ = NULL;
	gchar* _tmp98_ = NULL;
	mathgElmnt _tmp99_ = {0};
	mathgElmnt _tmp100_ = {0};
	g_return_if_fail (mc != NULL);
	_tmp0_ = (*self).term;
	_tmp1_ = g_new0 (gdouble, _tmp0_);
	ia = _tmp1_;
	ia_length1 = _tmp0_;
	_ia_size_ = ia_length1;
	_tmp2_ = (*self).term;
	_tmp3_ = g_new0 (gdouble, _tmp2_);
	tmpa = _tmp3_;
	tmpa_length1 = _tmp2_;
	_tmpa_size_ = tmpa_length1;
	{
		gint j = 0;
		j = 0;
		{
			gboolean _tmp4_ = FALSE;
			_tmp4_ = TRUE;
			while (TRUE) {
				gint _tmp6_ = 0;
				gint _tmp7_ = 0;
				gdouble* _tmp8_ = NULL;
				gint _tmp8__length1 = 0;
				gint _tmp9_ = 0;
				gdouble* _tmp10_ = NULL;
				gint _tmp10__length1 = 0;
				gint _tmp11_ = 0;
				gdouble _tmp12_ = 0.0;
				gdouble _tmp13_ = 0.0;
				gdouble _tmp14_ = 0.0;
				if (!_tmp4_) {
					gint _tmp5_ = 0;
					_tmp5_ = j;
					j = _tmp5_ + 1;
				}
				_tmp4_ = FALSE;
				_tmp6_ = j;
				_tmp7_ = (*self).term;
				if (!(_tmp6_ < _tmp7_)) {
					break;
				}
				_tmp8_ = tmpa;
				_tmp8__length1 = tmpa_length1;
				_tmp9_ = j;
				_tmp10_ = ia;
				_tmp10__length1 = ia_length1;
				_tmp11_ = j;
				_tmp12_ = mathg_operate_rand (&(*self));
				_tmp10_[_tmp11_] = _tmp12_;
				_tmp13_ = _tmp10_[_tmp11_];
				_tmp8_[_tmp9_] = _tmp13_;
				_tmp14_ = _tmp8_[_tmp9_];
			}
		}
	}
	_tmp15_ = (*self).term;
	_tmp16_ = g_new0 (gchar, _tmp15_ - 1);
	ca = _tmp16_;
	ca_length1 = _tmp15_ - 1;
	_ca_size_ = ca_length1;
	{
		gint j = 0;
		j = 0;
		{
			gboolean _tmp17_ = FALSE;
			_tmp17_ = TRUE;
			while (TRUE) {
				gint _tmp19_ = 0;
				gint _tmp20_ = 0;
				gchar* _tmp21_ = NULL;
				gint _tmp21__length1 = 0;
				gint _tmp22_ = 0;
				const gchar* _tmp23_ = NULL;
				const gchar* _tmp24_ = NULL;
				gint _tmp25_ = 0;
				gint _tmp26_ = 0;
				gint32 _tmp27_ = 0;
				gchar _tmp28_ = '\0';
				gchar _tmp29_ = '\0';
				if (!_tmp17_) {
					gint _tmp18_ = 0;
					_tmp18_ = j;
					j = _tmp18_ + 1;
				}
				_tmp17_ = FALSE;
				_tmp19_ = j;
				_tmp20_ = (*self).term;
				if (!(_tmp19_ < (_tmp20_ - 1))) {
					break;
				}
				_tmp21_ = ca;
				_tmp21__length1 = ca_length1;
				_tmp22_ = j;
				_tmp23_ = (*self).type;
				_tmp24_ = (*self).type;
				_tmp25_ = strlen (_tmp24_);
				_tmp26_ = _tmp25_;
				_tmp27_ = g_random_int_range ((gint32) 0, (gint32) _tmp26_);
				_tmp28_ = string_get (_tmp23_, (glong) _tmp27_);
				_tmp21_[_tmp22_] = _tmp28_;
				_tmp29_ = _tmp21_[_tmp22_];
			}
		}
	}
	div = 0;
	mul = 0;
	oth = 0;
	{
		gint j = 0;
		j = 0;
		{
			gboolean _tmp30_ = FALSE;
			_tmp30_ = TRUE;
			while (TRUE) {
				gint _tmp32_ = 0;
				gint _tmp33_ = 0;
				gchar* _tmp34_ = NULL;
				gint _tmp34__length1 = 0;
				gint _tmp35_ = 0;
				gchar _tmp36_ = '\0';
				if (!_tmp30_) {
					gint _tmp31_ = 0;
					_tmp31_ = j;
					j = _tmp31_ + 1;
				}
				_tmp30_ = FALSE;
				_tmp32_ = j;
				_tmp33_ = (*self).term;
				if (!(_tmp32_ < (_tmp33_ - 1))) {
					break;
				}
				_tmp34_ = ca;
				_tmp34__length1 = ca_length1;
				_tmp35_ = j;
				_tmp36_ = _tmp34_[_tmp35_];
				if (_tmp36_ == '/') {
					gint _tmp37_ = 0;
					gboolean _tmp38_ = FALSE;
					gint _tmp39_ = 0;
					gint _tmp40_ = 0;
					gdouble* _tmp45_ = NULL;
					gint _tmp45__length1 = 0;
					gint _tmp46_ = 0;
					gdouble* _tmp47_ = NULL;
					gint _tmp47__length1 = 0;
					gint _tmp48_ = 0;
					gdouble _tmp49_ = 0.0;
					gdouble _tmp50_ = 0.0;
					_tmp39_ = div;
					_tmp40_ = oth;
					if (_tmp39_ < _tmp40_) {
						_tmp38_ = TRUE;
					} else {
						gint _tmp41_ = 0;
						gint _tmp42_ = 0;
						_tmp41_ = div;
						_tmp42_ = mul;
						_tmp38_ = _tmp41_ < _tmp42_;
					}
					if (_tmp38_) {
						gint _tmp43_ = 0;
						_tmp43_ = j;
						_tmp37_ = _tmp43_;
					} else {
						gint _tmp44_ = 0;
						_tmp44_ = div;
						_tmp37_ = _tmp44_;
					}
					div = _tmp37_;
					_tmp45_ = ia;
					_tmp45__length1 = ia_length1;
					_tmp46_ = div;
					_tmp47_ = ia;
					_tmp47__length1 = ia_length1;
					_tmp48_ = j;
					_tmp49_ = _tmp47_[_tmp48_ + 1];
					_tmp45_[_tmp46_] *= _tmp49_;
					_tmp50_ = _tmp45_[_tmp46_];
				} else {
					gchar* _tmp51_ = NULL;
					gint _tmp51__length1 = 0;
					gint _tmp52_ = 0;
					gchar _tmp53_ = '\0';
					_tmp51_ = ca;
					_tmp51__length1 = ca_length1;
					_tmp52_ = j;
					_tmp53_ = _tmp51_[_tmp52_];
					if (_tmp53_ == 'x') {
						gint _tmp54_ = 0;
						gdouble* _tmp55_ = NULL;
						gint _tmp55__length1 = 0;
						gint _tmp56_ = 0;
						gdouble* _tmp57_ = NULL;
						gint _tmp57__length1 = 0;
						gint _tmp58_ = 0;
						gdouble _tmp59_ = 0.0;
						gdouble _tmp60_ = 0.0;
						_tmp54_ = j;
						mul = _tmp54_ + 1;
						_tmp55_ = tmpa;
						_tmp55__length1 = tmpa_length1;
						_tmp56_ = oth;
						_tmp57_ = ia;
						_tmp57__length1 = ia_length1;
						_tmp58_ = mul;
						_tmp59_ = _tmp57_[_tmp58_];
						_tmp55_[_tmp56_] *= _tmp59_;
						_tmp60_ = _tmp55_[_tmp56_];
					} else {
						gint _tmp61_ = 0;
						_tmp61_ = j;
						oth = _tmp61_ + 1;
					}
				}
			}
		}
	}
	_tmp62_ = i;
	_tmp63_ = g_strdup_printf ("%i", _tmp62_ + 1);
	_tmp64_ = _tmp63_;
	_tmp65_ = ia;
	_tmp65__length1 = ia_length1;
	_tmp66_ = _tmp65_[0];
	_tmp67_ = mathg_number_utils_ts (&(*mc).nu, _tmp66_);
	_tmp68_ = _tmp67_;
	_tmp69_ = string_to_string (_tmp68_);
	_tmp70_ = g_strconcat (_tmp64_, ")", _tmp69_, NULL);
	_tmp71_ = _tmp70_;
	_g_free0 (_tmp68_);
	_g_free0 (_tmp64_);
	q = _tmp71_;
	{
		gint j = 0;
		j = 1;
		{
			gboolean _tmp72_ = FALSE;
			_tmp72_ = TRUE;
			while (TRUE) {
				gint _tmp74_ = 0;
				gint _tmp75_ = 0;
				const gchar* _tmp76_ = NULL;
				gchar* _tmp77_ = NULL;
				gint _tmp77__length1 = 0;
				gint _tmp78_ = 0;
				gchar _tmp79_ = '\0';
				gchar* _tmp80_ = NULL;
				gchar* _tmp81_ = NULL;
				gdouble* _tmp82_ = NULL;
				gint _tmp82__length1 = 0;
				gint _tmp83_ = 0;
				gdouble _tmp84_ = 0.0;
				gchar* _tmp85_ = NULL;
				gchar* _tmp86_ = NULL;
				const gchar* _tmp87_ = NULL;
				gchar* _tmp88_ = NULL;
				gchar* _tmp89_ = NULL;
				gchar* _tmp90_ = NULL;
				if (!_tmp72_) {
					gint _tmp73_ = 0;
					_tmp73_ = j;
					j = _tmp73_ + 1;
				}
				_tmp72_ = FALSE;
				_tmp74_ = j;
				_tmp75_ = (*self).term;
				if (!(_tmp74_ < _tmp75_)) {
					break;
				}
				_tmp76_ = q;
				_tmp77_ = ca;
				_tmp77__length1 = ca_length1;
				_tmp78_ = j;
				_tmp79_ = _tmp77_[_tmp78_ - 1];
				_tmp80_ = g_strdup_printf ("%c", _tmp79_);
				_tmp81_ = _tmp80_;
				_tmp82_ = ia;
				_tmp82__length1 = ia_length1;
				_tmp83_ = j;
				_tmp84_ = _tmp82_[_tmp83_];
				_tmp85_ = mathg_number_utils_ts (&(*mc).nu, _tmp84_);
				_tmp86_ = _tmp85_;
				_tmp87_ = string_to_string (_tmp86_);
				_tmp88_ = g_strconcat (_tmp81_, _tmp87_, NULL);
				_tmp89_ = _tmp88_;
				_tmp90_ = g_strconcat (_tmp76_, _tmp89_, NULL);
				_g_free0 (q);
				q = _tmp90_;
				_g_free0 (_tmp89_);
				_g_free0 (_tmp86_);
				_g_free0 (_tmp81_);
			}
		}
	}
	_tmp91_ = i;
	_tmp92_ = tmpa;
	_tmp92__length1 = tmpa_length1;
	_tmp93_ = ca;
	_tmp93__length1 = ca_length1;
	_tmp94_ = mathg_operate_sumup (&(*self), _tmp92_, _tmp92__length1, _tmp93_, _tmp93__length1);
	_tmp95_ = q;
	_tmp96_ = string_to_string (_tmp95_);
	_tmp97_ = g_strconcat (_tmp96_, "=", NULL);
	_tmp98_ = _tmp97_;
	mathg_elmnt_init (&_tmp99_, _tmp94_, _tmp98_);
	mathg_elmnt_destroy (&(*mc).stra[_tmp91_]);
	(*mc).stra[_tmp91_] = _tmp99_;
	_tmp100_ = (*mc).stra[_tmp91_];
	_g_free0 (_tmp98_);
	_g_free0 (q);
	ca = (g_free (ca), NULL);
	tmpa = (g_free (tmpa), NULL);
	ia = (g_free (ia), NULL);
}


static gdouble mathg_operate_rand (mathgOperate *self) {
	gdouble result = 0.0;
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gdouble _tmp2_ = 0.0;
	gdouble _tmp3_ = 0.0;
	_tmp0_ = (*self).min;
	_tmp1_ = (*self).span;
	_tmp2_ = g_random_double ();
	_tmp3_ = exp (_tmp0_ + (_tmp1_ * _tmp2_));
	result = (gdouble) ((gint) _tmp3_);
	return result;
}


static gdouble mathg_operate_sumup (mathgOperate *self, gdouble* numa, int numa_length1, gchar* typea, int typea_length1) {
	gdouble result = 0.0;
	gdouble ans = 0.0;
	gdouble* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gdouble _tmp1_ = 0.0;
	_tmp0_ = numa;
	_tmp0__length1 = numa_length1;
	_tmp1_ = _tmp0_[0];
	ans = _tmp1_;
	{
		gint j = 0;
		j = 0;
		{
			gboolean _tmp2_ = FALSE;
			_tmp2_ = TRUE;
			while (TRUE) {
				gint _tmp4_ = 0;
				gchar* _tmp5_ = NULL;
				gint _tmp5__length1 = 0;
				gchar* _tmp6_ = NULL;
				gint _tmp6__length1 = 0;
				gint _tmp7_ = 0;
				gchar _tmp8_ = '\0';
				if (!_tmp2_) {
					gint _tmp3_ = 0;
					_tmp3_ = j;
					j = _tmp3_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp4_ = j;
				_tmp5_ = typea;
				_tmp5__length1 = typea_length1;
				if (!(_tmp4_ < _tmp5__length1)) {
					break;
				}
				_tmp6_ = typea;
				_tmp6__length1 = typea_length1;
				_tmp7_ = j;
				_tmp8_ = _tmp6_[_tmp7_];
				if (_tmp8_ == '+') {
					gdouble _tmp9_ = 0.0;
					gdouble* _tmp10_ = NULL;
					gint _tmp10__length1 = 0;
					gint _tmp11_ = 0;
					gdouble _tmp12_ = 0.0;
					_tmp9_ = ans;
					_tmp10_ = numa;
					_tmp10__length1 = numa_length1;
					_tmp11_ = j;
					_tmp12_ = _tmp10_[_tmp11_ + 1];
					ans = _tmp9_ + _tmp12_;
				} else {
					gchar* _tmp13_ = NULL;
					gint _tmp13__length1 = 0;
					gint _tmp14_ = 0;
					gchar _tmp15_ = '\0';
					_tmp13_ = typea;
					_tmp13__length1 = typea_length1;
					_tmp14_ = j;
					_tmp15_ = _tmp13_[_tmp14_];
					if (_tmp15_ == '-') {
						gdouble _tmp16_ = 0.0;
						gdouble* _tmp17_ = NULL;
						gint _tmp17__length1 = 0;
						gint _tmp18_ = 0;
						gdouble _tmp19_ = 0.0;
						_tmp16_ = ans;
						_tmp17_ = numa;
						_tmp17__length1 = numa_length1;
						_tmp18_ = j;
						_tmp19_ = _tmp17_[_tmp18_ + 1];
						ans = _tmp16_ - _tmp19_;
					}
				}
			}
		}
	}
	result = ans;
	return result;
}


void mathg_operate_copy (const mathgOperate* self, mathgOperate* dest) {
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gint _tmp2_ = 0;
	const gchar* _tmp3_ = NULL;
	gchar* _tmp4_ = NULL;
	_tmp0_ = (*self).min;
	(*dest).min = _tmp0_;
	_tmp1_ = (*self).span;
	(*dest).span = _tmp1_;
	_tmp2_ = (*self).term;
	(*dest).term = _tmp2_;
	_tmp3_ = (*self).type;
	_tmp4_ = g_strdup (_tmp3_);
	_g_free0 ((*dest).type);
	(*dest).type = _tmp4_;
}


void mathg_operate_destroy (mathgOperate* self) {
	_g_free0 ((*self).type);
}


mathgOperate* mathg_operate_dup (const mathgOperate* self) {
	mathgOperate* dup;
	dup = g_new0 (mathgOperate, 1);
	mathg_operate_copy (self, dup);
	return dup;
}


void mathg_operate_free (mathgOperate* self) {
	mathg_operate_destroy (self);
	g_free (self);
}


GType mathg_operate_get_type (void) {
	static volatile gsize mathg_operate_type_id__volatile = 0;
	if (g_once_init_enter (&mathg_operate_type_id__volatile)) {
		GType mathg_operate_type_id;
		mathg_operate_type_id = g_boxed_type_register_static ("mathgOperate", (GBoxedCopyFunc) mathg_operate_dup, (GBoxedFreeFunc) mathg_operate_free);
		g_once_init_leave (&mathg_operate_type_id__volatile, mathg_operate_type_id);
	}
	return mathg_operate_type_id__volatile;
}



