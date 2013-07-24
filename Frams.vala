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
	args = args[1:args.length];
	Gtk.init(ref args);
	var gw = new Gtk.Window();
	frame(gw, args.length != 7 ? new string[] {"8", "10", "100", "+", "5", "20", ".05"}: args);
	Gtk.main();
}

static void frame(Gtk.Window gw, string[] args) {
	gw.set_title("valamathg");
	Grid g = new Grid();
	gw.set_default_size(Screen.width(), 206);
	Label[] lb = new Label[8];
	for(int i = 0; i < 8; i++) {
		lb[i] = new Label(@"$i");
		g.attach(lb[i], 1, i, 1, 1);
	}
	gw.destroy.connect(main_quit);
	MathCog mc = MathCog(args);
	EventCog ec = new EventCog(g, mc, lb);
	gw.add(ec);
	gw.show_all();
	ec.repaint();
}
