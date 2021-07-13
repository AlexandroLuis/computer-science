public class CalendarFactory {
	public static Calendar createCalendar(String format) {
		if(format.equals("dd/MM/yyyy"))
			return new DMY(format);
		else{
			if(format.equals("MM/dd/yyyy"))
				return new MDY(format);
			else
				throw new IllegalArgumentException("");
		}
	}
}
