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
	public struct NumberUtils {
		uint bas;

		public NumberUtils(string s) {
			bas = 10;
			bas = ti(s);
		}

		internal double td(string a) {
			var sb = new StringBuilder(a);
			int i = sb.str.index_of_char('.');
			if(i < 0) {
				i = (int)sb.len;
			} else {
				sb.erase(i, 1);
			}
			double d = Math.pow(bas, sb.len - i);
			return tl(sb.str) / d;
		}

		internal int ti(string a) {
			return (int)tl(a);
		}

		internal int64 tl(string a) {
			return strtoll(a, null, bas);
		}

		internal string ts(int64 a) {
			bool neg = a < 0;
			string s = uts(a.abs());
			return neg ? @"-$s": s;
		}

		internal string uts(uint64 a) {
			if(bas == 10 || a < 2) {
				return @"$a";
			}
			var sb = new StringBuilder.sized(64);
			uint rest = 0;
			for(; a > 0; a /= bas) {
				rest = (uint)(a % bas);
				sb.prepend_c(digits[rest]);
			}
			return sb.str;
		}
	}

	[CCode(cname = "g_ascii_strtoll")]
	static extern int64 strtoll(string nptr, out char* endptr, uint _base);
}
