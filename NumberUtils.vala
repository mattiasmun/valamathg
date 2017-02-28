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
		int bas;

		public NumberUtils(string s) {
			bas = ti(s);
		}

		internal double td(string a) {
			return ti((a+".").split(("."))[0]);
		}

		internal int ti(string a) {
			return (int)strtoll(a, null, bas);
		}
		
		internal string ts(double d) {
			string s = "", t = "";
			int i = (int)d, j = 0;
			if(i < 0) {
				t = "-";
				i = -i;
			}
			while(i >= bas){
				j = i % bas;
				i /= bas;
				s = @"$j$s";
			}
			return @"$t$i$s";
		}
	}
	[CCode(cname = "g_ascii_strtoll")]
	static extern int64 strtoll(string nptr, out char* endptr, uint _base);
}
