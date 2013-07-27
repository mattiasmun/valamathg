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

using Gdk, Gtk, mathg;

public static void main(string[] args) {
	string[] data = args.length == 8 ? args[1: args.length]: ConfFile().tryread();
	Gtk.init(ref args);
	var gw = new Gtk.Window();
	frame(gw, data);
	Gtk.main();
}

static void frame(Gtk.Window gw, string[] args) {
	gw.set_title("valamathg");
	gw.set_default_size(Screen.width(), 206);
	gw.destroy.connect(main_quit);
	EventCog ec = new EventCog(args);
	gw.add(ec);
	gw.show_all();
	ec.repaint();
}
