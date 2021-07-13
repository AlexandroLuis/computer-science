public class Main {
	public static void main(String[] args) {
		Calendar objcalendar = CalendarFactory.createCalendar("dd/MM/yyyy"); // ("MM/dd/yyyy")
		System.out.println(objcalendar.getDate());
	}
}
