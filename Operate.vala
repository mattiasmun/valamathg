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

namespace mathg {
	static const string types = "+-x/";

	public struct Operate {
		int64 max;
		int64 min;
		int term;
		string typ;

		public Operate(int64 a, int64 b, string c, int d) {
			min = a;
			max = b;
			typ = checktype(c);
			term = d;
		}

		string checktype(string s) {
			for(int i = 0; i < s.length; i++) {
				assert(types.index_of_char(s[i]) > -1);
			}
			return s;
		}

		internal void oper(MathCog mc, int i) {
			var ia = new int64[term], tmpa = new int64[term];
			for(int j = 0; j < term; j++) {
				tmpa[j] = ia[j] = rand(min, max);
			}
			var ca = new char[term - 1];
			for(int j = 0; j < term - 1; j++) {
				ca[j] = typ[Random.int_range(0, typ.length)];
			}
			int div = 0, mul = 0, oth = 0;
			for(int j = 0; j < term - 1; j++) {
				if(ca[j] == '/') {
					div = div < oth || div < mul ? j: div;
					ia[div] *= ia[j + 1];
				} else if(ca[j] == 'x') {
					mul = j + 1;
					tmpa[oth] *= ia[mul];
				} else {
					oth = j + 1;
				}
			}
			int64 ans = tmpa[0];
			for(int j = 0; j < term - 1; j++) {
				if(ca[j] == '+') {
					ans += tmpa[j + 1];
				} else if(ca[j] == '-') {
					ans -= tmpa[j + 1];
				}
			}
			string q = @"$(i + 1))$(mc.nu.ts(ia[0]))";
			for(int j = 1; j < term; j++) {
				q += @"$(ca[j - 1])$(mc.nu.ts(ia[j]))";
			}
			mc.stra[i] = Elmnt(ans, @"$q=");
		}

		int64 rand(int64 a, int64 b) {
			int64 gen = ((int64)int.MAX + 1) * Random.next_int() + Random.next_int();
			return a + gen % (b - a);
		}
	}
}
