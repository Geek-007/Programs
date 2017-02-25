/**
 * Created by qqf on 16/02/2017.
 */

import java.awt.*;
import javax.swing.*;

public class GraphicsTester extends JFrame {
    public GraphicsTester(){
        super("font, color, draw");
        setVisible(true);
        setSize(480, 250);
    }

    public void paint(Graphics G){
        super.paint(G);
        G.setFont(new Font("SansSerif", Font.BOLD, 12));
        G.setColor(Color.BLUE);
        G.drawString("Font ScanSerif, bold, 12, blue", 20, 50);

        G.setFont(new Font("Serif", Font.ITALIC, 14));
        G.setColor(new Color(255, 0, 0));
        G.drawString("Font Serif, Italic, 14, red", 250, 50);

        G.drawLine(20, 60, 460, 60);

        G.setColor(Color.green);
        G.drawRect(20, 70, 100, 50);
        G.fillRect(130, 70, 100, 50);

        G.setColor(Color.yellow);
        G.drawRoundRect(240, 70 ,100, 50, 50 ,50);
        G.fillRoundRect(350, 70, 100, 50, 50, 50);

        G.setColor(Color.cyan);
        G.draw3DRect(20, 130, 100, 50, true);
        G.fill3DRect(130, 130, 100, 50, false);

        G.setColor(Color.pink);
        G.drawOval(240, 130, 100, 50);
        G.fillOval(350, 130, 100, 50);

        G.setColor(new Color(0, 120, 20));
        G.drawArc(20, 190, 100,50, 0, 90);
        G.fillArc(130, 190, 100, 50, 0, 90);

        G.setColor(Color.black);
        int [] xValues = {250, 280, 290, 300, 330, 310, 320, 290, 260, 270};
        int [] yValues = {210, 210, 190, 210, 210, 220, 230, 220, 230, 220};
        G.drawPolygon(xValues, yValues, 10);
    }

    public static void main(String[] args) {
        GraphicsTester app = new GraphicsTester();
        app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

}
