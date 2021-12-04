import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Priority;
import javafx.scene.layout.Region;
import javafx.scene.layout.VBox;
	public class Main extends Application{
		private Button Botao1;
		private Button Botao2;
		private Button Botao3;
	public static void main(String[] args){
		launch(args);
	}
	@Override
	public void start(Stage primaryStage){
		primaryStage.setTitle("VBox define os nós verticalmente");
		VBox vbox = new VBox();
		vbox.setAlignment(Pos.CENTER);
		vbox.setSpacing(10);
		Botao1 = new Button("Primeiro Botão");
		Botao2 = new Button("Segundo  Botão");
		Botao3 = new Button("Terceiro Botão");
		Region spacer = new Region();
		vbox.getChildren().addAll(Botao1, Botao2, spacer, Botao3);
		vbox.setPadding(new Insets(10));
		VBox.setVgrow(spacer, Priority.ALWAYS);
		Scene scene = new Scene(vbox, 300, 200);
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
