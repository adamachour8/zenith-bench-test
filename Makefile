COMPOSE_FILE := docker/docker-compose.yaml
COMPOSE := docker compose -f $(COMPOSE_FILE)
C ?= firmware

build:
	$(COMPOSE) build

up:
	$(COMPOSE) up -d $(C)

down:
	$(COMPOSE) down

shell:
	docker exec -it $(C) bash

logs:
	$(COMPOSE) logs -f $(C)