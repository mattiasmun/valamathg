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
	public struct ConfFile {
		static File _f;

		public static File cfgfile() {
			if(_f == null) {
				string s = Environment.get_user_config_dir();
				s += "/valamathg/valamathg.conf";
				_f = File.new_for_path(s);
				chkdir(_f);
			}
			return _f;
		}

		public static void chkdir(File f) {
			try {
				if(!f.get_parent().query_exists()){
					f.get_parent().make_directory_with_parents();
				}
			} catch(Error e) {
				stderr.printf ("%s\n", e.message);
			}
		}

		public static string[] getdata(File f = cfgfile()) {
			string s = "";
			try {
				// Test for the existence of file
				if (f.query_exists ()) {
					var data_stream = new DataInputStream(f.read());
					size_t st;
					s = data_stream.read_line_utf8(out st);
				} else {
					// Create a new file with its name and write text data to it
					var data_stream = new DataOutputStream(f.create(FileCreateFlags.NONE));
					s = "10 1 10 +/ 2 20 .01";
					data_stream.put_string(s);
				}
			} catch(Error e) {
				stderr.printf ("%s\n", e.message);
			}
			return s.split(" ");
		}
	}
}
