/* Operate.c generated by valac 0.22.1, the Vala compiler
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

struct _mathgOperate {
	gdouble min;
	gdouble span;
	gint term;
	gchar* type;
};

struct _mathgNumberUtils {
	guint bas;
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



#define MATHG_types "+-x/"
GType mathg_operate_get_type (void) G_GNUC_CONST;
mathgOperate* mathg_operate_dup (const mathgOperate* self);
void mathg_operate_free (mathgOperate* self);
void mathg_operate_copy (const mathgOperate* self, mathgOperate* dest);
void mathg_operate_destroy (mathgOperate* self);
void mathg_operate_init (mathgOperate *self, gint64 a, gint64 b, const gchar* c, gint d);
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
static gint64 mathg_operate_rand (mathgOperate *self);
gchar* mathg_number_utils_ts (mathgNumberUtils *self, gint64 a);
static gint64 mathg_operate_sumup (mathgOperate *self, gint64* numa, int numa_length1, gchar* typea, int typea_length1);
void mathg_elmnt_init (mathgElmnt *self, gint64 a, const gchar* s);


void mathg_operate_init (mathgOperate *self, gint64 a, gint64 b, const gchar* c, gint d) {
	gint64 _tmp0_ = 0LL;
	gdouble _tmp1_ = 0.0;
	gint64 _tmp2_ = 0LL;
	gdouble _tmp3_ = 0.0;
	gdouble _tmp4_ = 0.0;
	const gchar* _tmp5_ = NULL;
	gchar* _tmp6_ = NULL;
	gint _tmp7_ = 0;
	g_return_if_fail (c != NULL);
	memset (self, 0, sizeof (mathgOperate));
	_tmp0_ = a;
	_tmp1_ = log ((gdouble) _tmp0_);
	(*self).min = _tmp1_;
	_tmp2_ = b;
	_tmp3_ = log ((gdouble) _tmp2_);
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
	_tmp2_ = g_utf8_strchr (((gchar*) self) + _tmp0_, (gssize) (-1), _tmp1_);
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
	const gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	g_return_val_if_fail (s != NULL, NULL);
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp0_ = FALSE;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_ = FALSE;
				gint _tmp3_ = 0;
				const gchar* _tmp4_ = NULL;
				gint _tmp5_ = 0;
				gint _tmp6_ = 0;
				const gchar* _tmp7_ = NULL;
				gint _tmp8_ = 0;
				gchar _tmp9_ = '\0';
				gint _tmp10_ = 0;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_ = 0;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp0_ = FALSE;
				_tmp3_ = i;
				_tmp4_ = s;
				_tmp5_ = strlen (_tmp4_);
				_tmp6_ = _tmp5_;
				if (!(_tmp3_ < _tmp6_)) {
					break;
				}
				_tmp7_ = s;
				_tmp8_ = i;
				_tmp9_ = string_get (_tmp7_, (glong) _tmp8_);
				_tmp10_ = string_index_of_char (MATHG_types, (gunichar) _tmp9_, 0);
				_vala_assert (_tmp10_ > (-1), "types.index_of_char(s[i]) > -1");
			}
		}
	}
	_tmp11_ = s;
	_tmp12_ = g_strdup (_tmp11_);
	result = _tmp12_;
	return result;
}


static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void mathg_operate_oper (mathgOperate *self, mathgMathCog* mc, gint i) {
	gint64* ia = NULL;
	gint _tmp0_ = 0;
	gint64* _tmp1_ = NULL;
	gint ia_length1 = 0;
	gint _ia_size_ = 0;
	gint64* tmpa = NULL;
	gint _tmp2_ = 0;
	gint64* _tmp3_ = NULL;
	gint tmpa_length1 = 0;
	gint _tmpa_size_ = 0;
	gchar* ca = NULL;
	gint _tmp16_ = 0;
	gchar* _tmp17_ = NULL;
	gint ca_length1 = 0;
	gint _ca_size_ = 0;
	gint div = 0;
	gint mul = 0;
	gint oth = 0;
	gchar* q = NULL;
	gint _tmp67_ = 0;
	gchar* _tmp68_ = NULL;
	gchar* _tmp69_ = NULL;
	gint64* _tmp70_ = NULL;
	gint _tmp70__length1 = 0;
	gint64 _tmp71_ = 0LL;
	gchar* _tmp72_ = NULL;
	gchar* _tmp73_ = NULL;
	const gchar* _tmp74_ = NULL;
	gchar* _tmp75_ = NULL;
	gchar* _tmp76_ = NULL;
	gint _tmp97_ = 0;
	gint64* _tmp98_ = NULL;
	gint _tmp98__length1 = 0;
	gchar* _tmp99_ = NULL;
	gint _tmp99__length1 = 0;
	gint64 _tmp100_ = 0LL;
	const gchar* _tmp101_ = NULL;
	const gchar* _tmp102_ = NULL;
	gchar* _tmp103_ = NULL;
	gchar* _tmp104_ = NULL;
	mathgElmnt _tmp105_ = {0};
	mathgElmnt _tmp106_ = {0};
	g_return_if_fail (mc != NULL);
	_tmp0_ = (*self).term;
	_tmp1_ = g_new0 (gint64, _tmp0_);
	ia = _tmp1_;
	ia_length1 = _tmp0_;
	_ia_size_ = ia_length1;
	_tmp2_ = (*self).term;
	_tmp3_ = g_new0 (gint64, _tmp2_);
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
				gboolean _tmp5_ = FALSE;
				gint _tmp7_ = 0;
				gint _tmp8_ = 0;
				gint64* _tmp9_ = NULL;
				gint _tmp9__length1 = 0;
				gint _tmp10_ = 0;
				gint64* _tmp11_ = NULL;
				gint _tmp11__length1 = 0;
				gint _tmp12_ = 0;
				gint64 _tmp13_ = 0LL;
				gint64 _tmp14_ = 0LL;
				gint64 _tmp15_ = 0LL;
				_tmp5_ = _tmp4_;
				if (!_tmp5_) {
					gint _tmp6_ = 0;
					_tmp6_ = j;
					j = _tmp6_ + 1;
				}
				_tmp4_ = FALSE;
				_tmp7_ = j;
				_tmp8_ = (*self).term;
				if (!(_tmp7_ < _tmp8_)) {
					break;
				}
				_tmp9_ = tmpa;
				_tmp9__length1 = tmpa_length1;
				_tmp10_ = j;
				_tmp11_ = ia;
				_tmp11__length1 = ia_length1;
				_tmp12_ = j;
				_tmp13_ = mathg_operate_rand (&(*self));
				_tmp11_[_tmp12_] = _tmp13_;
				_tmp14_ = _tmp11_[_tmp12_];
				_tmp9_[_tmp10_] = _tmp14_;
				_tmp15_ = _tmp9_[_tmp10_];
			}
		}
	}
	_tmp16_ = (*self).term;
	_tmp17_ = g_new0 (gchar, _tmp16_ - 1);
	ca = _tmp17_;
	ca_length1 = _tmp16_ - 1;
	_ca_size_ = ca_length1;
	{
		gint j = 0;
		j = 0;
		{
			gboolean _tmp18_ = FALSE;
			_tmp18_ = TRUE;
			while (TRUE) {
				gboolean _tmp19_ = FALSE;
				gint _tmp21_ = 0;
				gint _tmp22_ = 0;
				gchar* _tmp23_ = NULL;
				gint _tmp23__length1 = 0;
				gint _tmp24_ = 0;
				const gchar* _tmp25_ = NULL;
				const gchar* _tmp26_ = NULL;
				gint _tmp27_ = 0;
				gint _tmp28_ = 0;
				gint32 _tmp29_ = 0;
				gchar _tmp30_ = '\0';
				gchar _tmp31_ = '\0';
				_tmp19_ = _tmp18_;
				if (!_tmp19_) {
					gint _tmp20_ = 0;
					_tmp20_ = j;
					j = _tmp20_ + 1;
				}
				_tmp18_ = FALSE;
				_tmp21_ = j;
				_tmp22_ = (*self).term;
				if (!(_tmp21_ < (_tmp22_ - 1))) {
					break;
				}
				_tmp23_ = ca;
				_tmp23__length1 = ca_length1;
				_tmp24_ = j;
				_tmp25_ = (*self).type;
				_tmp26_ = (*self).type;
				_tmp27_ = strlen (_tmp26_);
				_tmp28_ = _tmp27_;
				_tmp29_ = g_random_int_range ((gint32) 0, (gint32) _tmp28_);
				_tmp30_ = string_get (_tmp25_, (glong) _tmp29_);
				_tmp23_[_tmp24_] = _tmp30_;
				_tmp31_ = _tmp23_[_tmp24_];
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
			gboolean _tmp32_ = FALSE;
			_tmp32_ = TRUE;
			while (TRUE) {
				gboolean _tmp33_ = FALSE;
				gint _tmp35_ = 0;
				gint _tmp36_ = 0;
				gchar* _tmp37_ = NULL;
				gint _tmp37__length1 = 0;
				gint _tmp38_ = 0;
				gchar _tmp39_ = '\0';
				_tmp33_ = _tmp32_;
				if (!_tmp33_) {
					gint _tmp34_ = 0;
					_tmp34_ = j;
					j = _tmp34_ + 1;
				}
				_tmp32_ = FALSE;
				_tmp35_ = j;
				_tmp36_ = (*self).term;
				if (!(_tmp35_ < (_tmp36_ - 1))) {
					break;
				}
				_tmp37_ = ca;
				_tmp37__length1 = ca_length1;
				_tmp38_ = j;
				_tmp39_ = _tmp37_[_tmp38_];
				if (_tmp39_ == '/') {
					gint _tmp40_ = 0;
					gboolean _tmp41_ = FALSE;
					gint _tmp42_ = 0;
					gint _tmp43_ = 0;
					gboolean _tmp46_ = FALSE;
					gint _tmp49_ = 0;
					gint64* _tmp50_ = NULL;
					gint _tmp50__length1 = 0;
					gint _tmp51_ = 0;
					gint64* _tmp52_ = NULL;
					gint _tmp52__length1 = 0;
					gint _tmp53_ = 0;
					gint64 _tmp54_ = 0LL;
					gint64 _tmp55_ = 0LL;
					_tmp42_ = div;
					_tmp43_ = oth;
					if (_tmp42_ < _tmp43_) {
						_tmp41_ = TRUE;
					} else {
						gint _tmp44_ = 0;
						gint _tmp45_ = 0;
						_tmp44_ = div;
						_tmp45_ = mul;
						_tmp41_ = _tmp44_ < _tmp45_;
					}
					_tmp46_ = _tmp41_;
					if (_tmp46_) {
						gint _tmp47_ = 0;
						_tmp47_ = j;
						_tmp40_ = _tmp47_;
					} else {
						gint _tmp48_ = 0;
						_tmp48_ = div;
						_tmp40_ = _tmp48_;
					}
					_tmp49_ = _tmp40_;
					div = _tmp49_;
					_tmp50_ = ia;
					_tmp50__length1 = ia_length1;
					_tmp51_ = div;
					_tmp52_ = ia;
					_tmp52__length1 = ia_length1;
					_tmp53_ = j;
					_tmp54_ = _tmp52_[_tmp53_ + 1];
					_tmp50_[_tmp51_] *= _tmp54_;
					_tmp55_ = _tmp50_[_tmp51_];
				} else {
					gchar* _tmp56_ = NULL;
					gint _tmp56__length1 = 0;
					gint _tmp57_ = 0;
					gchar _tmp58_ = '\0';
					_tmp56_ = ca;
					_tmp56__length1 = ca_length1;
					_tmp57_ = j;
					_tmp58_ = _tmp56_[_tmp57_];
					if (_tmp58_ == 'x') {
						gint _tmp59_ = 0;
						gint64* _tmp60_ = NULL;
						gint _tmp60__length1 = 0;
						gint _tmp61_ = 0;
						gint64* _tmp62_ = NULL;
						gint _tmp62__length1 = 0;
						gint _tmp63_ = 0;
						gint64 _tmp64_ = 0LL;
						gint64 _tmp65_ = 0LL;
						_tmp59_ = j;
						mul = _tmp59_ + 1;
						_tmp60_ = tmpa;
						_tmp60__length1 = tmpa_length1;
						_tmp61_ = oth;
						_tmp62_ = ia;
						_tmp62__length1 = ia_length1;
						_tmp63_ = mul;
						_tmp64_ = _tmp62_[_tmp63_];
						_tmp60_[_tmp61_] *= _tmp64_;
						_tmp65_ = _tmp60_[_tmp61_];
					} else {
						gint _tmp66_ = 0;
						_tmp66_ = j;
						oth = _tmp66_ + 1;
					}
				}
			}
		}
	}
	_tmp67_ = i;
	_tmp68_ = g_strdup_printf ("%i", _tmp67_ + 1);
	_tmp69_ = _tmp68_;
	_tmp70_ = ia;
	_tmp70__length1 = ia_length1;
	_tmp71_ = _tmp70_[0];
	_tmp72_ = mathg_number_utils_ts (&(*mc).nu, _tmp71_);
	_tmp73_ = _tmp72_;
	_tmp74_ = string_to_string (_tmp73_);
	_tmp75_ = g_strconcat (_tmp69_, ")", _tmp74_, NULL);
	_tmp76_ = _tmp75_;
	_g_free0 (_tmp73_);
	_g_free0 (_tmp69_);
	q = _tmp76_;
	{
		gint j = 0;
		j = 1;
		{
			gboolean _tmp77_ = FALSE;
			_tmp77_ = TRUE;
			while (TRUE) {
				gboolean _tmp78_ = FALSE;
				gint _tmp80_ = 0;
				gint _tmp81_ = 0;
				const gchar* _tmp82_ = NULL;
				gchar* _tmp83_ = NULL;
				gint _tmp83__length1 = 0;
				gint _tmp84_ = 0;
				gchar _tmp85_ = '\0';
				gchar* _tmp86_ = NULL;
				gchar* _tmp87_ = NULL;
				gint64* _tmp88_ = NULL;
				gint _tmp88__length1 = 0;
				gint _tmp89_ = 0;
				gint64 _tmp90_ = 0LL;
				gchar* _tmp91_ = NULL;
				gchar* _tmp92_ = NULL;
				const gchar* _tmp93_ = NULL;
				gchar* _tmp94_ = NULL;
				gchar* _tmp95_ = NULL;
				gchar* _tmp96_ = NULL;
				_tmp78_ = _tmp77_;
				if (!_tmp78_) {
					gint _tmp79_ = 0;
					_tmp79_ = j;
					j = _tmp79_ + 1;
				}
				_tmp77_ = FALSE;
				_tmp80_ = j;
				_tmp81_ = (*self).term;
				if (!(_tmp80_ < _tmp81_)) {
					break;
				}
				_tmp82_ = q;
				_tmp83_ = ca;
				_tmp83__length1 = ca_length1;
				_tmp84_ = j;
				_tmp85_ = _tmp83_[_tmp84_ - 1];
				_tmp86_ = g_strdup_printf ("%c", _tmp85_);
				_tmp87_ = _tmp86_;
				_tmp88_ = ia;
				_tmp88__length1 = ia_length1;
				_tmp89_ = j;
				_tmp90_ = _tmp88_[_tmp89_];
				_tmp91_ = mathg_number_utils_ts (&(*mc).nu, _tmp90_);
				_tmp92_ = _tmp91_;
				_tmp93_ = string_to_string (_tmp92_);
				_tmp94_ = g_strconcat (_tmp87_, _tmp93_, NULL);
				_tmp95_ = _tmp94_;
				_tmp96_ = g_strconcat (_tmp82_, _tmp95_, NULL);
				_g_free0 (q);
				q = _tmp96_;
				_g_free0 (_tmp95_);
				_g_free0 (_tmp92_);
				_g_free0 (_tmp87_);
			}
		}
	}
	_tmp97_ = i;
	_tmp98_ = tmpa;
	_tmp98__length1 = tmpa_length1;
	_tmp99_ = ca;
	_tmp99__length1 = ca_length1;
	_tmp100_ = mathg_operate_sumup (&(*self), _tmp98_, _tmp98__length1, _tmp99_, _tmp99__length1);
	_tmp101_ = q;
	_tmp102_ = string_to_string (_tmp101_);
	_tmp103_ = g_strconcat (_tmp102_, "=", NULL);
	_tmp104_ = _tmp103_;
	mathg_elmnt_init (&_tmp105_, _tmp100_, _tmp104_);
	mathg_elmnt_destroy (&(*mc).stra[_tmp97_]);
	(*mc).stra[_tmp97_] = _tmp105_;
	_tmp106_ = (*mc).stra[_tmp97_];
	_g_free0 (_tmp104_);
	_g_free0 (q);
	ca = (g_free (ca), NULL);
	tmpa = (g_free (tmpa), NULL);
	ia = (g_free (ia), NULL);
}


static gint64 mathg_operate_rand (mathgOperate *self) {
	gint64 result = 0LL;
	gdouble _tmp0_ = 0.0;
	gdouble _tmp1_ = 0.0;
	gdouble _tmp2_ = 0.0;
	gdouble _tmp3_ = 0.0;
	_tmp0_ = (*self).min;
	_tmp1_ = (*self).span;
	_tmp2_ = g_random_double ();
	_tmp3_ = exp (_tmp0_ + (_tmp1_ * _tmp2_));
	result = (gint64) _tmp3_;
	return result;
}


static gint64 mathg_operate_sumup (mathgOperate *self, gint64* numa, int numa_length1, gchar* typea, int typea_length1) {
	gint64 result = 0LL;
	gint64 ans = 0LL;
	gint64* _tmp0_ = NULL;
	gint _tmp0__length1 = 0;
	gint64 _tmp1_ = 0LL;
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
				gboolean _tmp3_ = FALSE;
				gint _tmp5_ = 0;
				gchar* _tmp6_ = NULL;
				gint _tmp6__length1 = 0;
				gchar* _tmp7_ = NULL;
				gint _tmp7__length1 = 0;
				gint _tmp8_ = 0;
				gchar _tmp9_ = '\0';
				_tmp3_ = _tmp2_;
				if (!_tmp3_) {
					gint _tmp4_ = 0;
					_tmp4_ = j;
					j = _tmp4_ + 1;
				}
				_tmp2_ = FALSE;
				_tmp5_ = j;
				_tmp6_ = typea;
				_tmp6__length1 = typea_length1;
				if (!(_tmp5_ < _tmp6__length1)) {
					break;
				}
				_tmp7_ = typea;
				_tmp7__length1 = typea_length1;
				_tmp8_ = j;
				_tmp9_ = _tmp7_[_tmp8_];
				if (_tmp9_ == '+') {
					gint64 _tmp10_ = 0LL;
					gint64* _tmp11_ = NULL;
					gint _tmp11__length1 = 0;
					gint _tmp12_ = 0;
					gint64 _tmp13_ = 0LL;
					_tmp10_ = ans;
					_tmp11_ = numa;
					_tmp11__length1 = numa_length1;
					_tmp12_ = j;
					_tmp13_ = _tmp11_[_tmp12_ + 1];
					ans = _tmp10_ + _tmp13_;
				} else {
					gchar* _tmp14_ = NULL;
					gint _tmp14__length1 = 0;
					gint _tmp15_ = 0;
					gchar _tmp16_ = '\0';
					_tmp14_ = typea;
					_tmp14__length1 = typea_length1;
					_tmp15_ = j;
					_tmp16_ = _tmp14_[_tmp15_];
					if (_tmp16_ == '-') {
						gint64 _tmp17_ = 0LL;
						gint64* _tmp18_ = NULL;
						gint _tmp18__length1 = 0;
						gint _tmp19_ = 0;
						gint64 _tmp20_ = 0LL;
						_tmp17_ = ans;
						_tmp18_ = numa;
						_tmp18__length1 = numa_length1;
						_tmp19_ = j;
						_tmp20_ = _tmp18_[_tmp19_ + 1];
						ans = _tmp17_ - _tmp20_;
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



