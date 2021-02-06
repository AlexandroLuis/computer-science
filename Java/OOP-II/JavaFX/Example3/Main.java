import javafx.application.*;

import javafx.collections.FXCollections; import javafx.collections.ObservableList; import javafx.scene.*;
import javafx.stage.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class Main extends Application {

public static void main(String[] args) { launch(args);

}

public void start(Stage stage) {
BorderPane root = new BorderPane();
root.setPadding(new Insets(10));
GridPane grid = new GridPane();
grid.setHgap(7);

grid.setVgap(7);

Label lblNome = new Label("Nome: "); TextField tfdNome = new TextField(); grid.add(lblNome, 0, 0); grid.add(tfdNome, 1, 0);

Label lblEmail = new Label("Email: "); TextField tfdEmail = new TextField(); grid.add(lblEmail, 0, 1); grid.add(tfdEmail, 1, 1);

Label lblSexo = new Label("Sexo: "); grid.add(lblSexo, 0, 2);

RadioButton btnMasc = new RadioButton("Masculino"); btnMasc.setSelected(true);

RadioButton btnFem = new RadioButton("Feminino");

ToggleGroup tgpSexo = new ToggleGroup(); btnMasc.setToggleGroup(tgpSexo); btnFem.setToggleGroup(tgpSexo);
HBox hboxRadioBtn = new HBox(5.0, btnMasc, btnFem); grid.add(hboxRadioBtn, 1, 2);

Label lblCurso = new Label("Curso: ");
ChoiceBox<String> cbCurso = new
ChoiceBox(FXCollections.observableArrayList("Ciência da

Computação","Engenharia de Alimentos", "Física", "Matemática",

"Química"));
cbCurso.getSelectionModel().selectFirst();
grid.add(lblCurso,0,3);

grid.add(cbCurso, 1, 3);

root.setCenter(grid);

Button btnGravar = new Button("Gravar"); Button btnCancelar = new Button("Cancelar");

HBox hbox = new HBox(5);
hbox.getChildren().addAll(btnGravar, btnCancelar);
root.setBottom(hbox);
hbox.setAlignment(Pos.BASELINE_RIGHT);

Scene scene = new Scene(root, 300, 200); stage.setScene(scene);

stage.show();
}
}
