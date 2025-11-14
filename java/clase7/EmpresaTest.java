package clase7;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThat;
import org.hamcrest.CoreMatchers;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

import java.util.ArrayList;
import java.util.Scanner;

@RunWith(MockitoJUnitRunner.class)
public class EmpresaTest {

	private Empresa empresa;

	@Before
	public void setup() {
		this.empresa = new Empresa();
	}

	@Test
	public void shouldMain() {
		// TODO: initialize args
		String[] args;

		Empresa.main(args);

		// TODO: assert scenario
	}
}
