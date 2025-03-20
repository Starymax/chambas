function flipCard() {
    const card = document.querySelector('.sobre');
    const hoja = document.querySelector('.hoja-container');
  
    if (hojaAbierta) {
      hoja.classList.add('regreso');
      hoja.classList.remove('salida');
      hoja.classList.remove('no-hover');
      hojaAbierta = false;
    }

    card.classList.toggle('flipped');
  }
  
  let hojaAbierta = false;

  window.onload = () => {
    const hojaContainer = document.querySelector('.hoja-container');
    hojaContainer.classList.add('regreso');
  };
  
  function toggleHoja(event) {
    event.stopPropagation();
  
    const hojaContainer = document.querySelector('.hoja-container');
  
    if (!hojaAbierta) {
      hojaContainer.classList.add('salida');
      hojaContainer.classList.remove('regreso');
      hojaContainer.classList.add('no-hover');
    } else {
      hojaContainer.classList.add('regreso');
      hojaContainer.classList.remove('salida');
      hojaContainer.classList.remove('no-hover');
    }
  
    hojaAbierta = !hojaAbierta;
  }

  function marcarCasilla(event, casilla) {
    event.stopPropagation();
  
    if (casilla.classList.contains('marcada')) {
      casilla.src = 'casilla.png';
      casilla.classList.remove('marcada');
    } else {
      casilla.src = 'casilla2.png';
      casilla.classList.add('marcada');
      const imagen = document.getElementById('bolaamarilla');
      imagen.src = 'qlo.png';
      const audio = document.getElementById('lengua');
      audio.play();
      generarCorazones();
    }
}


  let contador = 0;

  function verificarCasilla(event, casilla, otraCasilla) {
    event.stopPropagation();

    if (contador < 11){

        if (otraCasilla.src.includes('casilla2.png'))
            otraCasilla.src = 'casilla.png';

    const audio = document.getElementById('boom');
    audio.play();
  
    const imagen = document.getElementById('bolaamarilla');
    const texto = document.getElementById('non');

    if (contador === 0) {
        texto.textContent = 'que';
        imagen.src = 'tite.png';
      } else if (contador === 1) {
        texto.textContent = 'nomanches';
        imagen.src = 'tite1.png';
      } else if (contador === 2) {
        texto.textContent = 'cmo qno';
        imagen.src = 'tite2.png';
      } else if (contador === 3) {
        texto.textContent = ' pq';
        imagen.src = 'tite3.png';
      } else if (contador === 4) {
        texto.textContent = ':(';
        imagen.src = 'tite4.png';
      } else if (contador === 5) {
        texto.textContent = 'pero si yo \nt amo';
        imagen.src = 'tite5.png';
      } else if (contador === 6) {
        texto.textContent = 'yaestuvo suave';
        imagen.src = 'tite6.png';
      } else if (contador === 7) {
        texto.textContent = 't pasas \noye';
        imagen.src = 'tite7.png';
      } else if (contador === 8) {
        texto.textContent = 'yase';
        imagen.src = 'tite8.png';
      } else if (contador === 9) {
        texto.textContent = 'ci';
        imagen.src = 'tite9.png';
      } else if (contador > 9) {
        const imagen = document.getElementById('bolaamarilla');
        imagen.src = 'flor.png';
      } 
    
      contador++;
    } else
        casilla.src = 'casilla2.png';
  }

  function generarCorazones() {
    const contenedorCorazones = document.getElementById('animacion-corazones');
  
    for (let i = 0; i < 25; i++) {
      const heart = document.createElement('div');
      heart.classList.add('heart');

      heart.style.left = `${Math.random() * 350 - 200}px`;
      heart.style.top = `${Math.random() * 20 - 10}px`;
  
      heart.style.setProperty('--random-x', `${Math.random() * 200 - 100}px`); 
      heart.style.setProperty('--random-y', `${Math.random() * -300 - 100}px`); 
  
      contenedorCorazones.appendChild(heart);
  
      setTimeout(() => {
        heart.remove();
      }, 4000);
    }
  }
  