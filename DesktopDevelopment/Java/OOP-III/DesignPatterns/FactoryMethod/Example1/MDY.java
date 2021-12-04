public class MDY implements Calendar {
	private String format;
	
	public MDY(String format) {
		this.format = format;
	}

	@Override
	public String getDate() {
		SimpleDateFormat sdf = new SimpleDateFormat(format);
		Date date = new Date();
		return sdf.format(date);
	}
}
