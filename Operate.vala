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
	const string types = "+-x/";

	public struct Operate {
		double min;
		double span;
		int term;
		string type;

		public Operate(double a, double b, string c, int d) {
			min = Math.log(a);
			span = Math.log(b) - min;
			type = checktype(c);
			term = d;
		}

		string checktype(string s) {
			for(int i = 0; i < s.length; i++) {
				assert(types.index_of_char(s[i]) > -1);
			}
			return s;
		}

		internal void oper(MathCog mc, int i) {
			var ia = new double[term], tmpa = new double[term];
			for(int j = 0; j < term; j++) {
				tmpa[j] = ia[j] = rand();
			}
			var ca = new char[term - 1];
			for(int j = 0; j < term - 1; j++) {
				ca[j] = type[Random.int_range(0, type.length)];
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
			string q = @"$(i + 1))$(ia[0])";
			for(int j = 1; j < term; j++) {
				q += @"$(ca[j - 1])$(ia[j])";
			}
			mc.stra[i] = Elmnt(sumup(tmpa, ca), @"$q=");
		}

		double rand() {
			return Math.exp(min + span * Random.next_double());
		}

		double sumup(double[] numa, char[] typea) {
			double ans = numa[0];
			for(int j = 0; j < typea.length; j++) {
				if(typea[j] == '+') {
					ans += numa[j + 1];
				} else if(typea[j] == '-') {
					ans -= numa[j + 1];
				}
			}
			return ans;
		}
	}
}
