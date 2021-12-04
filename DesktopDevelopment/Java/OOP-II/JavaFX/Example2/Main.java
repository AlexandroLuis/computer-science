import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
public class Main extends Application {
	private Label lblNome;
	private Label lblMsg;
	private Button btnOla;
	private Button btnSair;
	TextField tfdNome;
	public static void main(String[] args) {
		launch(args);
	}
	@Override
	public void start(Stage primaryStage) {
		lblNome = new Label("Digite seu nome: ");
		tfdNome = new TextField();
		lblMsg = new Label();
		lblMsg.setStyle("-fx-text-fill: blue;");
		btnOla = new Button("Olá");
		btnSair = new Button("Sair");
		btnOla.setOnAction(e -> {
		String name = tfdNome.getText();
		if(name.trim().length() > 0)
			lblMsg.setText("Olá " + name + "!");
		else 
			lblMsg.setText("Olá! ");
		});
		btnSair.setOnAction(e - {Platform.exit();});
		VBox vbox = new VBox();
		vbox.setSpacing(4);
		vbox.setPadding(new Insets(12));
		vbox.getChildren().addAll(lblNome, tfdNome,lblMsg,btnOla, btnSair);
		Scene scene = new Scene(vbox, 300, 140);
		primaryStage.setTitle("Olá Olá JavaFX");
		primaryStage.setScene(scene);
		primaryStage.show();
}
