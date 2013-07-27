/* Operate.c generated by valac 0.18.1, the Vala compiler
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
	gint64 max;
	gint64 min;
	gint term;
	gchar* typ;
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
static gint64 mathg_operate_rand (mathgOperate *self, gint64 a, gint64 b);
gchar* mathg_number_utils_ts (mathgNumberUtils *self, gint64 a);
void mathg_elmnt_init (mathgElmnt *self, gint64 a, const gchar* s);


void mathg_operate_init (mathgOperate *self, gint64 a, gint64 b, const gchar* c, gint d) {
	gint64 _tmp0_;
	gint64 _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_ = NULL;
	gint _tmp4_;
	g_return_if_fail (c != NULL);
	memset (self, 0, sizeof (mathgOperate));
	_tmp0_ = a;
	(*self).min = _tmp0_;
	_tmp1_ = b;
	(*self).max = _tmp1_;
	_tmp2_ = c;
	_tmp3_ = mathg_operate_checktype (&(*self), _tmp2_);
	_g_free0 ((*self).typ);
	(*self).typ = _tmp3_;
	_tmp4_ = d;
	(*self).term = _tmp4_;
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


static gchar* mathg_operate_checktype (mathgOperate *self, const gchar* s) {
	gchar* result = NULL;
	const gchar* _tmp11_;
	gchar* _tmp12_;
	g_return_val_if_fail (s != NULL, NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				gboolean _tmp1_;
				gint _tmp3_;
				const gchar* _tmp4_;
				gint _tmp5_;
				gint _tmp6_;
				const gchar* _tmp7_;
				gint _tmp8_;
				gchar _tmp9_ = '\0';
				gint _tmp10_ = 0;
				_tmp1_ = _tmp0_;
				if (!_tmp1_) {
					gint _tmp2_;
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
	gint _tmp0_;
	gint64* _tmp1_ = NULL;
	gint64* ia;
	gint ia_length1;
	gint _ia_size_;
	gint _tmp2_;
	gint64* _tmp3_ = NULL;
	gint64* tmpa;
	gint tmpa_length1;
	gint _tmpa_size_;
	gint _tmp18_;
	gchar* _tmp19_ = NULL;
	gchar* ca;
	gint ca_length1;
	gint _ca_size_;
	gint div;
	gint mul;
	gint oth;
	gint64* _tmp69_;
	gint _tmp69__length1;
	gint64 _tmp70_;
	gint64 ans;
	gint _tmp90_;
	gchar* _tmp91_ = NULL;
	gchar* _tmp92_;
	gint64* _tmp93_;
	gint _tmp93__length1;
	gint64 _tmp94_;
	gchar* _tmp95_ = NULL;
	gchar* _tmp96_;
	const gchar* _tmp97_ = NULL;
	gchar* _tmp98_ = NULL;
	gchar* _tmp99_;
	gchar* q;
	gint _tmp120_;
	gint64 _tmp121_;
	const gchar* _tmp122_;
	const gchar* _tmp123_ = NULL;
	gchar* _tmp124_ = NULL;
	gchar* _tmp125_;
	mathgElmnt _tmp126_ = {0};
	mathgElmnt _tmp127_;
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
		gint j;
		j = 0;
		{
			gboolean _tmp4_;
			_tmp4_ = TRUE;
			while (TRUE) {
				gboolean _tmp5_;
				gint _tmp7_;
				gint _tmp8_;
				gint64* _tmp9_;
				gint _tmp9__length1;
				gint _tmp10_;
				gint64* _tmp11_;
				gint _tmp11__length1;
				gint _tmp12_;
				gint64 _tmp13_;
				gint64 _tmp14_;
				gint64 _tmp15_ = 0LL;
				gint64 _tmp16_;
				gint64 _tmp17_;
				_tmp5_ = _tmp4_;
				if (!_tmp5_) {
					gint _tmp6_;
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
				_tmp13_ = (*self).min;
				_tmp14_ = (*self).max;
				_tmp15_ = mathg_operate_rand (&(*self), _tmp13_, _tmp14_);
				_tmp11_[_tmp12_] = _tmp15_;
				_tmp16_ = _tmp11_[_tmp12_];
				_tmp9_[_tmp10_] = _tmp16_;
				_tmp17_ = _tmp9_[_tmp10_];
			}
		}
	}
	_tmp18_ = (*self).term;
	_tmp19_ = g_new0 (gchar, _tmp18_ - 1);
	ca = _tmp19_;
	ca_length1 = _tmp18_ - 1;
	_ca_size_ = ca_length1;
	{
		gint j;
		j = 0;
		{
			gboolean _tmp20_;
			_tmp20_ = TRUE;
			while (TRUE) {
				gboolean _tmp21_;
				gint _tmp23_;
				gint _tmp24_;
				gchar* _tmp25_;
				gint _tmp25__length1;
				gint _tmp26_;
				const gchar* _tmp27_;
				const gchar* _tmp28_;
				gint _tmp29_;
				gint _tmp30_;
				gint32 _tmp31_ = 0;
				gchar _tmp32_ = '\0';
				gchar _tmp33_;
				_tmp21_ = _tmp20_;
				if (!_tmp21_) {
					gint _tmp22_;
					_tmp22_ = j;
					j = _tmp22_ + 1;
				}
				_tmp20_ = FALSE;
				_tmp23_ = j;
				_tmp24_ = (*self).term;
				if (!(_tmp23_ < (_tmp24_ - 1))) {
					break;
				}
				_tmp25_ = ca;
				_tmp25__length1 = ca_length1;
				_tmp26_ = j;
				_tmp27_ = (*self).typ;
				_tmp28_ = (*self).typ;
				_tmp29_ = strlen (_tmp28_);
				_tmp30_ = _tmp29_;
				_tmp31_ = g_random_int_range ((gint32) 0, (gint32) _tmp30_);
				_tmp32_ = string_get (_tmp27_, (glong) _tmp31_);
				_tmp25_[_tmp26_] = _tmp32_;
				_tmp33_ = _tmp25_[_tmp26_];
			}
		}
	}
	div = 0;
	mul = 0;
	oth = 0;
	{
		gint j;
		j = 0;
		{
			gboolean _tmp34_;
			_tmp34_ = TRUE;
			while (TRUE) {
				gboolean _tmp35_;
				gint _tmp37_;
				gint _tmp38_;
				gchar* _tmp39_;
				gint _tmp39__length1;
				gint _tmp40_;
				gchar _tmp41_;
				_tmp35_ = _tmp34_;
				if (!_tmp35_) {
					gint _tmp36_;
					_tmp36_ = j;
					j = _tmp36_ + 1;
				}
				_tmp34_ = FALSE;
				_tmp37_ = j;
				_tmp38_ = (*self).term;
				if (!(_tmp37_ < (_tmp38_ - 1))) {
					break;
				}
				_tmp39_ = ca;
				_tmp39__length1 = ca_length1;
				_tmp40_ = j;
				_tmp41_ = _tmp39_[_tmp40_];
				if (_tmp41_ == '/') {
					gint _tmp42_ = 0;
					gboolean _tmp43_ = FALSE;
					gint _tmp44_;
					gint _tmp45_;
					gboolean _tmp48_;
					gint _tmp51_;
					gint64* _tmp52_;
					gint _tmp52__length1;
					gint _tmp53_;
					gint64* _tmp54_;
					gint _tmp54__length1;
					gint _tmp55_;
					gint64 _tmp56_;
					gint64 _tmp57_;
					_tmp44_ = div;
					_tmp45_ = oth;
					if (_tmp44_ < _tmp45_) {
						_tmp43_ = TRUE;
					} else {
						gint _tmp46_;
						gint _tmp47_;
						_tmp46_ = div;
						_tmp47_ = mul;
						_tmp43_ = _tmp46_ < _tmp47_;
					}
					_tmp48_ = _tmp43_;
					if (_tmp48_) {
						gint _tmp49_;
						_tmp49_ = j;
						_tmp42_ = _tmp49_;
					} else {
						gint _tmp50_;
						_tmp50_ = div;
						_tmp42_ = _tmp50_;
					}
					_tmp51_ = _tmp42_;
					div = _tmp51_;
					_tmp52_ = ia;
					_tmp52__length1 = ia_length1;
					_tmp53_ = div;
					_tmp54_ = ia;
					_tmp54__length1 = ia_length1;
					_tmp55_ = j;
					_tmp56_ = _tmp54_[_tmp55_ + 1];
					_tmp52_[_tmp53_] *= _tmp56_;
					_tmp57_ = _tmp52_[_tmp53_];
				} else {
					gchar* _tmp58_;
					gint _tmp58__length1;
					gint _tmp59_;
					gchar _tmp60_;
					_tmp58_ = ca;
					_tmp58__length1 = ca_length1;
					_tmp59_ = j;
					_tmp60_ = _tmp58_[_tmp59_];
					if (_tmp60_ == 'x') {
						gint _tmp61_;
						gint64* _tmp62_;
						gint _tmp62__length1;
						gint _tmp63_;
						gint64* _tmp64_;
						gint _tmp64__length1;
						gint _tmp65_;
						gint64 _tmp66_;
						gint64 _tmp67_;
						_tmp61_ = j;
						mul = _tmp61_ + 1;
						_tmp62_ = tmpa;
						_tmp62__length1 = tmpa_length1;
						_tmp63_ = oth;
						_tmp64_ = ia;
						_tmp64__length1 = ia_length1;
						_tmp65_ = mul;
						_tmp66_ = _tmp64_[_tmp65_];
						_tmp62_[_tmp63_] *= _tmp66_;
						_tmp67_ = _tmp62_[_tmp63_];
					} else {
						gint _tmp68_;
						_tmp68_ = j;
						oth = _tmp68_ + 1;
					}
				}
			}
		}
	}
	_tmp69_ = tmpa;
	_tmp69__length1 = tmpa_length1;
	_tmp70_ = _tmp69_[0];
	ans = _tmp70_;
	{
		gint j;
		j = 0;
		{
			gboolean _tmp71_;
			_tmp71_ = TRUE;
			while (TRUE) {
				gboolean _tmp72_;
				gint _tmp74_;
				gint _tmp75_;
				gchar* _tmp76_;
				gint _tmp76__length1;
				gint _tmp77_;
				gchar _tmp78_;
				_tmp72_ = _tmp71_;
				if (!_tmp72_) {
					gint _tmp73_;
					_tmp73_ = j;
					j = _tmp73_ + 1;
				}
				_tmp71_ = FALSE;
				_tmp74_ = j;
				_tmp75_ = (*self).term;
				if (!(_tmp74_ < (_tmp75_ - 1))) {
					break;
				}
				_tmp76_ = ca;
				_tmp76__length1 = ca_length1;
				_tmp77_ = j;
				_tmp78_ = _tmp76_[_tmp77_];
				if (_tmp78_ == '+') {
					gint64 _tmp79_;
					gint64* _tmp80_;
					gint _tmp80__length1;
					gint _tmp81_;
					gint64 _tmp82_;
					_tmp79_ = ans;
					_tmp80_ = tmpa;
					_tmp80__length1 = tmpa_length1;
					_tmp81_ = j;
					_tmp82_ = _tmp80_[_tmp81_ + 1];
					ans = _tmp79_ + _tmp82_;
				} else {
					gchar* _tmp83_;
					gint _tmp83__length1;
					gint _tmp84_;
					gchar _tmp85_;
					_tmp83_ = ca;
					_tmp83__length1 = ca_length1;
					_tmp84_ = j;
					_tmp85_ = _tmp83_[_tmp84_];
					if (_tmp85_ == '-') {
						gint64 _tmp86_;
						gint64* _tmp87_;
						gint _tmp87__length1;
						gint _tmp88_;
						gint64 _tmp89_;
						_tmp86_ = ans;
						_tmp87_ = tmpa;
						_tmp87__length1 = tmpa_length1;
						_tmp88_ = j;
						_tmp89_ = _tmp87_[_tmp88_ + 1];
						ans = _tmp86_ - _tmp89_;
					}
				}
			}
		}
	}
	_tmp90_ = i;
	_tmp91_ = g_strdup_printf ("%i", _tmp90_ + 1);
	_tmp92_ = _tmp91_;
	_tmp93_ = ia;
	_tmp93__length1 = ia_length1;
	_tmp94_ = _tmp93_[0];
	_tmp95_ = mathg_number_utils_ts (&(*mc).nu, _tmp94_);
	_tmp96_ = _tmp95_;
	_tmp97_ = string_to_string (_tmp96_);
	_tmp98_ = g_strconcat (_tmp92_, ")", _tmp97_, NULL);
	_tmp99_ = _tmp98_;
	_g_free0 (_tmp96_);
	_g_free0 (_tmp92_);
	q = _tmp99_;
	{
		gint j;
		j = 1;
		{
			gboolean _tmp100_;
			_tmp100_ = TRUE;
			while (TRUE) {
				gboolean _tmp101_;
				gint _tmp103_;
				gint _tmp104_;
				const gchar* _tmp105_;
				gchar* _tmp106_;
				gint _tmp106__length1;
				gint _tmp107_;
				gchar _tmp108_;
				gchar* _tmp109_ = NULL;
				gchar* _tmp110_;
				gint64* _tmp111_;
				gint _tmp111__length1;
				gint _tmp112_;
				gint64 _tmp113_;
				gchar* _tmp114_ = NULL;
				gchar* _tmp115_;
				const gchar* _tmp116_ = NULL;
				gchar* _tmp117_ = NULL;
				gchar* _tmp118_;
				gchar* _tmp119_;
				_tmp101_ = _tmp100_;
				if (!_tmp101_) {
					gint _tmp102_;
					_tmp102_ = j;
					j = _tmp102_ + 1;
				}
				_tmp100_ = FALSE;
				_tmp103_ = j;
				_tmp104_ = (*self).term;
				if (!(_tmp103_ < _tmp104_)) {
					break;
				}
				_tmp105_ = q;
				_tmp106_ = ca;
				_tmp106__length1 = ca_length1;
				_tmp107_ = j;
				_tmp108_ = _tmp106_[_tmp107_ - 1];
				_tmp109_ = g_strdup_printf ("%c", _tmp108_);
				_tmp110_ = _tmp109_;
				_tmp111_ = ia;
				_tmp111__length1 = ia_length1;
				_tmp112_ = j;
				_tmp113_ = _tmp111_[_tmp112_];
				_tmp114_ = mathg_number_utils_ts (&(*mc).nu, _tmp113_);
				_tmp115_ = _tmp114_;
				_tmp116_ = string_to_string (_tmp115_);
				_tmp117_ = g_strconcat (_tmp110_, _tmp116_, NULL);
				_tmp118_ = _tmp117_;
				_tmp119_ = g_strconcat (_tmp105_, _tmp118_, NULL);
				_g_free0 (q);
				q = _tmp119_;
				_g_free0 (_tmp118_);
				_g_free0 (_tmp115_);
				_g_free0 (_tmp110_);
			}
		}
	}
	_tmp120_ = i;
	_tmp121_ = ans;
	_tmp122_ = q;
	_tmp123_ = string_to_string (_tmp122_);
	_tmp124_ = g_strconcat (_tmp123_, "=", NULL);
	_tmp125_ = _tmp124_;
	mathg_elmnt_init (&_tmp126_, _tmp121_, _tmp125_);
	mathg_elmnt_destroy (&(*mc).stra[_tmp120_]);
	(*mc).stra[_tmp120_] = _tmp126_;
	_tmp127_ = (*mc).stra[_tmp120_];
	_g_free0 (_tmp125_);
	_g_free0 (q);
	ca = (g_free (ca), NULL);
	tmpa = (g_free (tmpa), NULL);
	ia = (g_free (ia), NULL);
}


static gint64 mathg_operate_rand (mathgOperate *self, gint64 a, gint64 b) {
	gint64 result = 0LL;
	gint _tmp0_;
	guint32 _tmp1_ = 0U;
	guint32 _tmp2_ = 0U;
	gint64 gen;
	gint64 _tmp3_;
	gint64 _tmp4_;
	gint64 _tmp5_;
	_tmp0_ = G_MAXINT;
	_tmp1_ = g_random_int ();
	_tmp2_ = g_random_int ();
	gen = ((((gint64) _tmp0_) + 1) * _tmp1_) + _tmp2_;
	_tmp3_ = a;
	_tmp4_ = b;
	_tmp5_ = a;
	result = _tmp3_ + (gen % (_tmp4_ - _tmp5_));
	return result;
}


void mathg_operate_copy (const mathgOperate* self, mathgOperate* dest) {
	gint64 _tmp0_;
	gint64 _tmp1_;
	gint _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	_tmp0_ = (*self).max;
	(*dest).max = _tmp0_;
	_tmp1_ = (*self).min;
	(*dest).min = _tmp1_;
	_tmp2_ = (*self).term;
	(*dest).term = _tmp2_;
	_tmp3_ = (*self).typ;
	_tmp4_ = g_strdup (_tmp3_);
	_g_free0 ((*dest).typ);
	(*dest).typ = _tmp4_;
}


void mathg_operate_destroy (mathgOperate* self) {
	_g_free0 ((*self).typ);
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



