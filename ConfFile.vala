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
		File f;

		public ConfFile() {
			string s = Environment.get_user_config_dir();
			s += "/valamathg/valamathg.conf";
			f = File.new_for_path(s);
		}

		void mkdir() {
			try {
				f.get_parent().make_directory_with_parents();
			} catch(Error e) {
				stderr.printf ("%s\n", e.message);
			}
		}
		
		public string[] tryread() {
			try {
				var data_stream = new DataInputStream(f.read());
				size_t st;
				return data_stream.read_line_utf8(out st).split(" ");
			} catch(Error e) {
				stderr.printf ("%s\n", e.message);
				return trywrite();
			}
		}
		
		public string[] trywrite(string s = "10 1 10 +/ 2 20 .01") {
			try {
				mkdir();
				var file_stream = f.create(FileCreateFlags.NONE);
				var data_stream = new DataOutputStream(file_stream);
				data_stream.put_string(s);
			} catch(Error e) {
				stderr.printf ("%s\n", e.message);
			}
			return s.split(" ");
		}
	}
}
