/* valamathg.vapi generated by valac 0.34.4, do not modify. */

namespace mathg {
	[CCode (cheader_filename = "valamathg.h")]
	public class EventCog : Gtk.Viewport {
		public EventCog (string[] args);
		public void repaint ();
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct ConfFile {
		public GLib.File f;
		public ConfFile ();
		public string[] tryread ();
		public string[] trywrite (string s = "10 1 10 +/ 2 20 .01");
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct Elmnt {
		public double answer;
		public string guess;
		public string question;
		public string result;
		public Elmnt (double a, string s);
		public string to_string ();
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct MathCog {
		public string ch;
		public double cor;
		public double deviation;
		public double err;
		public bool isenter;
		public mathg.NumberUtils nu;
		public mathg.Operate operation;
		public int pm;
		public mathg.MyTimer problem;
		public string res;
		public mathg.Elmnt[] stra;
		public int straind;
		public mathg.MyTimer total;
		public MathCog (string[] args);
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct MyTimer {
		public bool reset;
		public GLib.DateTime start;
		public GLib.DateTime stop;
		public MyTimer (bool b);
		public string to_string ();
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct NumberUtils {
		public uint bas;
		public NumberUtils (string s);
	}
	[CCode (cheader_filename = "valamathg.h")]
	public struct Operate {
		public double min;
		public double span;
		public int term;
		public string type;
		public Operate (double a, double b, string c, int d);
	}
}
