public class CalendarFactory {
	public static Calendar createCalendar(String format) {
		if(format.equals("yyyy/MM/ddHH:mm:ss"))
			return new DMY(format);
		else{
			if(format.equals("MM/dd/yyyyhh:mm:ss"))
				return new MDY(format);
			else
				throw new IllegalArgumentException("");
		}
	}
}
