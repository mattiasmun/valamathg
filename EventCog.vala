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

using Gdk, Gtk;

namespace mathg {
	static const string[] sa = {"xx-large", "x-large", "large", "medium"};

	public class EventCog: Viewport {
		bool ctrl = false;
		MathCog mc;
		uint kod;
		Label[] lb;

		public EventCog(string[] args) {
			Grid g = new Grid();
			lb = new Label[8];
			for(int i = 0; i < 8; i++) {
				lb[i] = new Label(@"$i");
				g.attach(lb[i], 1, i, 1, 1);
			}
			add(g);
			mc = MathCog(args);
			can_focus = true;
			grab_focus();
		}

		void caseixy(int i) {
			int j = mc.straind + i - 3;
			if(mc.straind + i > 2 && j < mc.stra.length) {
				string s = @"<span size=\"$(sa[(i - 3).abs()])\">";
				s = @"$s$(mc.stra[j])</span>";
				lb[i].set_markup(s);
			} else {
				lb[i].set_text("");
			}
		}

		bool is_ctrl() {
			return kod == Key.Control_L || kod == Key.Control_R;
		}

		bool is_enter() {
			return kod == Key.KP_Enter || kod == Key.Return;
		}

		internal override bool key_press_event(EventKey event) {
			mc.ch = event.str.replace("§","0");
			kod = event.keyval;
			mc.isenter = is_enter();
			switch(kod) {
			case Key.BackSpace: mc.bsp();
				break;
			case Key.Q: case Key.q: if(ctrl) {
					main_quit();
				}
				break;
			case Key.R: case Key.r: if(ctrl) {
					mc.generate();
				}
				break;
			}
			ctrl = is_ctrl() ? true: ctrl;
			if(mc.stra[mc.straind].result == null) {
				mc.put();
			}
			repaint();
			return true;
		}

		internal override bool key_release_event(EventKey event) {
			ctrl = is_ctrl() ? false: ctrl;
			return true;
		}

		public void repaint() {
			for(int i = 0; i < 7; i++) {
				caseixy(i);
			}
			lb[7].set_text(mc.res);
		}

		internal override bool scroll_event(EventScroll event) {
			int scr = (int)event.delta_y;
			mc.straind += mc.straind + scr < mc.stra.length && mc.straind + scr >= 0 ? scr: 0;
			repaint();
			return true;
		}
	}
}
