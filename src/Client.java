import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import java.awt.BorderLayout;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

public class Client {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 500);
		frame.setContentPane(new JPanel(new BorderLayout()));
		frame.getContentPane().add(new JLabel("Hi!"), BorderLayout.CENTER);
		frame.setVisible(true);
		frame.addKeyListener(new KeyListener() {
			public void keyTyped(KeyEvent e) {}
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_SPACE) {
					System.exit(0);
				}
				if(e.getKeyCode() == KeyEvent.VK_W) {
					System.out.println("W");
				}
				if(e.getKeyCode() == KeyEvent.VK_A) {
					System.out.println("A");
				}
				if(e.getKeyCode() == KeyEvent.VK_S) {
					System.out.println("S");
				}
				if(e.getKeyCode() == KeyEvent.VK_D) {
					System.out.println("D");
				}
			}
			public void keyReleased(KeyEvent e) {
				if(e.getKeyCode() == KeyEvent.VK_W) {
					System.out.println("w");
				}
				if(e.getKeyCode() == KeyEvent.VK_A) {
					System.out.println("a");
				}
				if(e.getKeyCode() == KeyEvent.VK_S) {
					System.out.println("s");
				}
				if(e.getKeyCode() == KeyEvent.VK_D) {
					System.out.println("d");
				}
			}
		});
	}
}