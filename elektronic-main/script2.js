function glowbtn(t) {
	a = document.getElementById('test')
	if (a.style.display != 'block') {
		if (t == 'over')
			document.getElementById('testbtn').style.backgroundImage = 'url(\'testh.png\')'
		else
			document.getElementById('testbtn').style.backgroundImage = 'url(\'test.png\')'
	}
}

function showtest() {
	a = document.getElementById('test')
	if (a.style.display == 'block') {

		for (i=0; i < qcount; i++) {
			qform = document.getElementById('q'+i)
			n = qform.length
			for (j=0; j < n; j++)
				if (qform[j].checked) qform[j].checked = false
		}

		a.style.display = 'none'
		document.getElementById('results').style.display = 'none'
		document.getElementById('testbtn').style.backgroundImage = 'url(\'test.png\')'
	} else {
		a.style.display = 'block'
		document.getElementById('testbtn').style.backgroundImage = 'url(\'testc.png\')'
	}
}

function check() {
	userAnsw = Array(qcount) 	
	

	for (i=0; i < qcount; i++) {
		userAnsw[i] = -1
		qform = document.getElementById('q'+i)
		n = qform.length
		for (j=0; j < n; j++)
			if (qform[j].checked) userAnsw[i] = j
	}

	r = 0
	w = 0
	for (i=0; i < qcount; i++) {
		if (userAnsw[i] == questAnsw[i]) r++
		else w++
	}

	oc = (r / qcount) * 100
        b = 0
	if (oc >= 85) b = 5
	else if (oc >= 60) b = 4
	else if (oc >= 45) b = 3
	else b = 2
	
	document.getElementById('results').style.display = 'block';
	document.getElementById('right').innerHTML = 'Правильн: ' + r
	document.getElementById('wrong').innerHTML = 'Неправильно: ' + w
	document.getElementById('ball').innerHTML = 'Оценка: ' + b
}