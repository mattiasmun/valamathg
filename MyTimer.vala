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
	public struct MyTimer {
		bool reset;
		DateTime start;
		DateTime stop;

		public MyTimer(bool b) {
			reset = b;
			start = stop = new DateTime.now_local();
		}

		public string to_string() {
			stop = new DateTime.now_local();
			var s = @"$((stop.difference(start) + 500L)/1000L)";
			start = reset ? stop: start;
			return s;
		}
    }
}
