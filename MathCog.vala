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
	const string digits = "0123456789abcdefghijklmnopqrstuvwxyz";

	public struct MathCog {
		string ch;
		double cor;
		double deviation;
		double err;
		bool isenter;
		NumberUtils nu;
		Operate operation;
		int pm;
		MyTimer problem;
		string res;
		Elmnt[] stra;
		int straind;
		MyTimer total;

		public MathCog(string[] args) {
			nu = NumberUtils(args[0]);
			pm = nu.ti("1000");
			operation = Operate(nu.td(args[1]), nu.td(args[2]), args[3], nu.ti(args[4]));
			stra = new Elmnt[nu.ti(args[5]) > 1 ? nu.ti(args[5]): 1];
			deviation = nu.td(args[6]);
			generate();
		}

		internal void bsp() {
			string s = stra[straind].guess;
			stra[straind].guess = s.substring(0, s.length - 1);
		}

		void close(double ans) {
			double hyp = nu.td(stra[straind].guess);
			double d = (hyp - ans).abs();
			cor += ans.abs();
			err += d;
			stra[straind].result = @" ans=$(nu.ts(ans)) Δ=$(nu.ts(d)) t=";
			stra[straind].result += @"$(problem)ms";
			res = "tot Δ‰=";
			res += @"$(err / cor * pm)";
			res += @" Δ=$(nu.ts(err)) t=$(total)ms";
			straind += straind < stra.length - 1 ? 1: 0;
		}

		internal void generate() {
			cor = err = straind = 0;
			res = "tot Δ‰=0 Δ=0 t=0ms";
			problem = MyTimer(true);
			total = MyTimer(false);
			for(int b = 0; b < stra.length; b++) {
				operation.oper(this, b);
			}
		}

		internal void put() {
			string s = stra[straind].guess;
			if(ch == "-") {
				s = s.contains("-") ? s.substring(1): ch + s;
			} else if(digits.substring(0, nu.bas).contains(ch)) {
				s += ch;
			}
			double d = nu.td(s);
			stra[straind].guess = s;
			double ans = stra[straind].answer;
			if(Math.fabs(d / ans - 1) <= deviation || isenter) {
				close(ans);
			}
			isenter = false;
		}
	}
}
