import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.MenuItem;
public class FXMLDocumentController {
	@FXML
	private MenuItem menuExit;
	@FXML
	private Button btnSalve;
	@FXML
	private Button btnCancel;
	@FXML
	private void acaoBotaoSave(ActionEvent event) {
		Platform.exit();
	}
	@FXML
	private void acaoBotaoCancel(ActionEvent event) {
		Platform.exit();
	}
	@FXML
	private void acaoMenuExit(ActionEvent event) {
		Platform.exit();
	}
}
