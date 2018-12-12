const	express = require('express');
const	db		= require('./utils/db.query');
const	bodyParser = require('body-parser');
const	apiRouter = require('./apiRouter').router;

const	app = express();

app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json());

app.get('/', function(req, res) {
	res.status(200).send('Bienvenue sur Matcha, le premier site de rencontres pour ennuques !');
});

app.use('/api/', apiRouter);

app.listen(8080, function() {
	console.log('Serveur lancé sur le port 8080 !');
});