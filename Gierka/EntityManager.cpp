#include "EntityManager.h"

// Constructors and destructor

EntityManager::EntityManager() {


}

void EntityManager::update(GameCamera* gameCamera) {

		if (gameCamera->getyOffset() < 585 * 48 && gameCamera->getyOffset() > 584 * 48) {
			p->setPosition((float)(7 * 48), (float)(580 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 560 * 48 && gameCamera->getyOffset() > 559 * 48) {
			p->setPosition((float)(23 * 48), (float)(557 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 535 * 48 && gameCamera->getyOffset() > 534 * 48) {
			p->setPosition((float)(24 * 48), (float)(530 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 513 * 48 && gameCamera->getyOffset() > 512 * 48) {
			p->setPosition((float)(7 * 48), (float)(509 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 485 * 48 && gameCamera->getyOffset() > 484 * 48) {
			p->setPosition((float)(24 * 48), (float)(480 * 48));
			p->setActivity(true);
		}


		else if (gameCamera->getyOffset() < 455 * 48 && gameCamera->getyOffset() > 454 * 48) {
			p->setPosition((float)(24 * 48), (float)(450 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 426 * 48 && gameCamera->getyOffset() > 425 * 48) {
			p->setPosition((float)(11 * 48), (float)(424.5 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 405 * 48 && gameCamera->getyOffset() > 404 * 48) {
			p->setPosition((float)(24 * 48), (float)(400 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 380 * 48 && gameCamera->getyOffset() > 379 * 48) {
			p->setPosition((float)(7 * 48), (float)(376 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 357 * 48 && gameCamera->getyOffset() > 356 * 48) {
			p->setPosition((float)(21 * 48), (float)(355 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 325 * 48 && gameCamera->getyOffset() > 324 * 48) {
			p->setPosition((float)(7.5 * 48), (float)(322.5 * 48));
			p->setActivity(true);
		}


		else if (gameCamera->getyOffset() < 302 * 48 && gameCamera->getyOffset() > 301 * 48) {
			p->setPosition((float)(7 * 48), (float)(300 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 280 * 48 && gameCamera->getyOffset() > 279 * 48) {
			p->setPosition((float)(11 * 48), (float)(275 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 255 * 48 && gameCamera->getyOffset() > 254 * 48) {
			p->setPosition((float)(23 * 48), (float)(253.5 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 231 * 48 && gameCamera->getyOffset() > 230 * 48) {
			p->setPosition((float)(24.5 * 48), (float)(224 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 205 * 48 && gameCamera->getyOffset() > 204 * 48) {
			p->setPosition((float)(7 * 48), (float)(202 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 183 * 48 && gameCamera->getyOffset() > 182 * 48) {
			p->setPosition((float)(22 * 48), (float)(177 * 48));
			p->setActivity(true);
		}


		else if (gameCamera->getyOffset() < 155 * 48 && gameCamera->getyOffset() > 154 * 48) {
			p->setPosition((float)(9 * 48), (float)(150 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 128 * 48 && gameCamera->getyOffset() > 127 * 48) {
			p->setPosition((float)(7 * 48), (float)(128 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 108 * 48 && gameCamera->getyOffset() > 107 * 48) {
			p->setPosition((float)(22 * 48), (float)(108 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 88 * 48 && gameCamera->getyOffset() > 87 * 48) {
			p->setPosition((float)(7 * 48), (float)(86 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 67 * 48 && gameCamera->getyOffset() > 66 * 48) {
			p->setPosition((float)(24 * 48), (float)(64 * 48));
			p->setActivity(true);
		}
		else if (gameCamera->getyOffset() < 44 * 48 && gameCamera->getyOffset() > 43 * 48) {
			p->setPosition((float)(7.5 * 48), (float)(40 * 48));
			p->setActivity(true);
		}

}

void EntityManager::render(sf::RenderWindow* window, GameCamera* gameCamera) {

		if(p->isActive())
			p->render(window, gameCamera);
}

void EntityManager::setPoint(Points* e) {
	p=e;
}

Points* EntityManager::getPoint() {
	return p;
}